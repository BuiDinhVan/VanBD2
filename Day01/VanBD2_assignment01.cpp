#include<iostream>
#include<list>
using namespace std;

bool CheckPalindrome(long long number){
    if (number < 0)
    {
        number *= -1;                                   // chuyển thành số dương
    }
    string num = to_string(number);
    list<char> list_num(num.begin(), num.end()) ;
    while (!(list_num.empty()))
    {
        if(list_num.back() == '0'){
            list_num.pop_back();                        // bỏ các số 0 ở sau
        }else{
            if(list_num.front() != list_num.back()){    // so sánh các số đối xứng hay không
                return false;
            }else{
                list_num.pop_back();
                list_num.pop_front();
            }
        }
    }
    return true;
}

int main(){
    long long n;
    printf("Nhap vao so n: ");
    cin >> n;
    if(CheckPalindrome(n)){
        printf("True");
    }else{
        printf("False");
    }
    return 0;
}