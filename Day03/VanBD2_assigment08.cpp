#include <iostream>
using namespace std;

/****************************************************************
 * Input: str Mainstring 
 *        sub Substring
 * Return: The first position appear of Substring in Mainstring
 * Descrition: Find the position of Substring in Mainstring
 ***************************************************************/
int findsubstr(const char *str, char *sub){
    int indexSub = 0, mark = -1;
    for(int i = 0; str[i] != '\0'; i++){
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
        if(sub[indexSub] == '\0')
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
