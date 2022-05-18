#include <iostream>
using namespace std;

/***************************************************************
 * Input: str String
 * Return: the length of string
 * Descrition: count the length of string
 ****************************************************************/
int lengOfStr(const char* str){
    int len = 0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}

/****************************************************************
 * Input: str Mainstring 
 *        sub Substring
 * Return: The first position appear of Substring in Mainstring
 * Descrition: Find the position of Substring in Mainstring
 ***************************************************************/
int findsubstr(const char *str, char *sub){
    int lenMainStr = lengOfStr(str);
    int lenSubStr = lengOfStr(sub);
    int indexSub = 0, mark = -1;
    for(int i = 0; i < lenMainStr ; i++){
        if(sub[indexSub] == str[i]){
            if(sub[indexSub] == str[i+1])
                continue;
            if(indexSub == 0)
                mark = i;
            indexSub++;
        }
        else{
            indexSub = 0;
            mark = -1;
        }
        if(indexSub == lenSubStr)
            return mark;
    }
    return mark;
}

int main()
{
    char str[] = "Hello world, my name is Van";
    char sub[] = "lo";
    cout << "The first position appear: ";
    cout << findsubstr(str,sub);
    return 0;
}