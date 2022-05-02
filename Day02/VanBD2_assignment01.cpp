#include<iostream>
using namespace std;

int* get_even_num(int* arr, int* sz){
    int size = *sz = *arr;
    int* ptr = new int[*sz];
    int index = 0;
    for (int i = 1; i <= size; i++)
    {
        if (*(arr + i) % 2 == 0)
        {
            *(ptr + index) = *(arr + i);
            index++;
        }else{
            (*sz)--;
        }
    }
    return ptr;
}

int main(){
    int test[] = {10, 1, 2, 3, 11, 5, 6, 12, 8, 9, 10};
    int sz;
    int* a = get_even_num(test, &sz);
    for (int i = 0; i < sz; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << sz;
    free(a);
    return 0;
}