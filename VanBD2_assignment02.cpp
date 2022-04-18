#include<iostream>

using namespace std;

int main(){
    int m;
    do{
        cin >> m;                       // nhập vào số lẻ
    }while(m <= 2 || (m % 2 == 0));
    // khởi tạo mảng khoảng trống
    char arr[m][m];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = ' ';
        }
    }

    int a,b;                            // giá trị khoảng vẽ từ a -> b
    a = b = m / 2;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(j >= a && j <= b){
                arr[i][j] = '*';
            }
        }
        if(i < m /2){                   // nửa mảng đầu
            a--;
            b++;
        }else{                          // nửa mảng sau
            a++;
            b--;
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}