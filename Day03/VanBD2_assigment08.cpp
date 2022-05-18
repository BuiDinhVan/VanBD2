#include <iostream>
using namespace std;

/***************************************************************
* Input: str: Mainstring
*        indexMain: the begin position to check
*        sub: Substring
* Return: true: Mainstring contains Substring
*         false: Mainstring doesn't contain Substring
* Descrition: Check if Mainstring contains Substring
****************************************************************/
bool checkFindsubstr(const char* str, int indexMain, char* sub) {
    for (int i = 1; sub[i] != '\0'; i++) {
        if (str[indexMain++] != sub[i])
            return false;
    }
    return true;
}

/****************************************************************
 * Input: str Mainstring
 *        sub Substring
 * Return: The first position appear of Substring in Mainstring
 * Descrition: Find the position of Substring in Mainstring
 ***************************************************************/
int findsubstr(const char* str, char* sub) {
    int indexMain = 0, mark = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sub[0]) {
            indexMain = i + 1;
            if (checkFindsubstr(str, indexMain, sub)) {
                mark = i;
                return mark;
            }
        }
    }
    return mark;
}

int main()
{
    char str[] = "Helllo world, my name is Van";
    char sub[] = "llo";
    cout << "The first position appear: ";
    cout << findsubstr(str, sub);
    return 0;
}
