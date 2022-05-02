#include<iostream>
#include<cstring>
using namespace std;

struct bitMapFileHeader
{
    unsigned char bfType[2];
    unsigned char bfSize[4];
    unsigned char bfReserved1[2];
    unsigned char bfReserved2[2];
    unsigned char bfOffset[4];
};

struct bitMapInfoHeader
{
    unsigned long biSize;
    unsigned long biWidth;
    unsigned long biHeight;
    unsigned short biPlanes;
    unsigned short biBitsperPixel;
    unsigned long biCompression;
    unsigned long biImageSize;
    unsigned long biX_PixelsPerMeter;
    unsigned long biY_PixelsPerMeter;
    unsigned long biColorsTable;
    unsigned long biColorsImportant;
};

struct Pixel
{
    unsigned char B;
    unsigned char R;
    unsigned char G;
};


bool bmp_reverse(const char* bmp_path, const char* reverse_bmp_path){
    FILE* f;
    bitMapFileHeader fileHeader;
    bitMapInfoHeader infoHeader;
    unsigned char* dataImage;

    f = fopen(bmp_path, "rb");
    if(!f){
        cout << "File is not open" << endl;
        return false;
    }

    fread(&fileHeader, sizeof(bitMapFileHeader), 1, f);
    if (fileHeader.bfType[0] != 0x42 || fileHeader.bfType[1] != 0x4D){
        cout << "This is not file BM" << endl;
        fclose(f);
        return false;
    }
    
    fread(&infoHeader, sizeof(bitMapInfoHeader), 1, f);
    int padding = (infoHeader.biWidth * 3) % 4;
    int sizeOfImage = infoHeader.biWidth * infoHeader.biHeight * 3 + padding * infoHeader.biHeight;

    dataImage = new unsigned char[sizeOfImage];
    if (!dataImage){
        free(dataImage);
        fclose(f);
        return false;
    }
    memset(dataImage, 0, sizeOfImage);
    fread(dataImage, sizeOfImage, 1, f);
    if (!dataImage){
        fclose(f);
        return false;
    }
    fclose(f);

    f = fopen(reverse_bmp_path, "wb");
    if (!f){
        cout << "File is not open" << endl;
        return false;
    }
    fwrite(&fileHeader, sizeof(bitMapFileHeader), 1, f);
    fwrite(&infoHeader, sizeof(bitMapInfoHeader), 1, f);

    Pixel* pixel = new Pixel[infoHeader.biWidth * infoHeader.biHeight];
    if (!pixel){
        free(pixel);
        fclose(f);
        return false;
    }
    memset(pixel, 0, infoHeader.biWidth * infoHeader.biHeight);
    // chuyển mảng BitMap vào mảng Pixel đồng thời Reverse 
    for (int y = infoHeader.biHeight - 1; y >= 0; y--){
        for (int x = 0; x < infoHeader.biWidth; x++){
            pixel [y * infoHeader.biWidth + x].B = *(dataImage++);
            pixel [y * infoHeader.biWidth + x].R = *(dataImage++);
            pixel [y * infoHeader.biWidth + x].G = *(dataImage++);
        }
        dataImage = dataImage + padding;
    }

    unsigned char* data_reverse = new unsigned char[sizeOfImage];
    if (!data_reverse){
        free(data_reverse);
        fclose(f);
        return false;
    }
    memset(data_reverse, 0, sizeOfImage);
    unsigned char* temp = data_reverse;
    // Chuyển mảng Pixel vào mảng BitMap
    for (int y = 0; y < infoHeader.biHeight; y++){
        for (int x = 0; x < infoHeader.biWidth; x++){
            *(temp++) = pixel[y * infoHeader.biWidth + x].B;
            *(temp++) = pixel[y * infoHeader.biWidth + x].R;
            *(temp++) = pixel[y * infoHeader.biWidth + x].G;
        }
        for(int i = 0; i < padding; i++){
            *(temp++) = 0;
        }
    }
    /* REVERSE trực tiếp
    for (int y = infoHeader.biHeight - 1; y >= 0; y--){
        for (int x = 0; x < infoHeader.biWidth * 3; x++){
            *(temp++) = dataImage[y * (infoHeader.biWidth * 3 + padding) + x];
        }
        for(int i = 0; i < padding; i++){
            *(temp++) = 0;
        }
    }
    */
    fwrite(data_reverse, sizeOfImage, 1, f);
    fclose(f);
    free(dataImage);
    free(pixel);
    free(data_reverse);
    return true;
}

int main(){
    if (bmp_reverse("Test2.bmp", "Create.bmp"))
    {
        cout << "File is create" << endl;
    }else{
        cout << "File is not create" << endl;
    }
    return 0;
}