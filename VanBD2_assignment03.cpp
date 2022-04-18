#include<iostream>
using namespace std;

int main(){
    unsigned short date, month, year, endDate_February;
    cout << "\nCLENDAR\n\n";
    cout << "Input dd/mm/yyyy\n";
    // xét nhập ngày tháng năm đúng hay không
    while (1){
        cout << "date: "; cin >> date;          // nhập ngày 
        if(date < 1 || date > 31){
            continue;
        }
        cout << "month: "; cin >> month;        // nhập tháng
        if(month < 1 || month > 12){
            continue;
        }else if(month == 2 && date > 29){
            cout << "ERROR: This month only have 28 or 29 day\n";
            continue;
        }else if((month == 4 || month == 6 || month == 9 || month == 11) && date > 30){
            cout << "ERROR: This month only have 30 day\n";
            continue;
        }
        cout << "year: "; cin >> year;          // nhập năm
        if(month == 2){
            if(date == 29 && !((year % 4 == 0) && (year % 100 != 0))){      // ngày 29 và năm không nhuận
                cout << "ERROR: This year, February only have 28 day\n";
                continue;
            }else{
                break;
            }
        }else{
            break;
        }
    } 
    // Xét là năm nhuận hay không nhuận
    if((year % 4 == 0) && (year % 100 != 0)){
        endDate_February = 29;
    }else{
        endDate_February = 28;
    }

    while(1){
        cout << "\n===========MENU===========\n";
        cout << "1. Find the number of month\n";
        cout << "2. Show next day (dd/mm/yyyy)\n";
        cout << "3. Show previous day (dd/mm/yyyy)\n";
        unsigned short select;
        cout << "\nSelect option: ";
        cin >> select;
        unsigned short temp_date = date;            
        unsigned short temp_month = month;          // các biến trung gian
        unsigned short temp_year = year;
        string str_date, str_month;             // biến có số 0 nếu số < 10
        switch (select)
        {
        case 1:                         // Find the number of month
            unsigned short number;
            if(month == 2){
                number = endDate_February;
            }else if(month == 4 || month == 6 || month == 9 || month == 11){
                number = 30;
            }else{
                number = 31;
            }
            printf("The number of month: %d\n", number);
            break;
        case 2:                         // Show next day (dd/mm/yyyy)
            if (date == 31 && (month != 2 || month != 4 || month != 6 || month != 9 || month != 11))  // ngày cuối của tháng 31 ngày
            {
                temp_date = 1;
                if(month != 12){
                    temp_month++;
                }else{                  // ngày cuối năm
                    temp_month = 1;
                    temp_year++;
                }
            }else if(date == 30 && (month == 4 || month == 6 || month == 9 || month == 11)){   // ngày cuối của tháng 30 ngày
                temp_date = 1;
                temp_month++;
            }else if(date == endDate_February && month == 2){    // ngày cuối của tháng 2
                temp_date = 1;
                temp_month++;
            }else{                                  // những ngày còn lại
                temp_date++;
            }
            str_date = to_string(temp_date);
            str_month = to_string(temp_month);
            if(temp_date < 10){
                str_date = '0' + str_date;
            }
            if(temp_month < 10){
                str_month = '0' + str_month;
            }
            cout << "The next day: " << str_date << '/' << str_month << '/' << temp_year << endl;
            break;
        case 3:                            // Show previous day (dd/mm/yyyy)
            if(date == 1 & month == 3){    
                temp_date = endDate_February;
                temp_month--;
            }else if(date == 1 && (month == 5 || month == 7 || month == 10 || month == 12)){
                temp_date = 30;
                temp_month--;
            }else if(date == 1 && (month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)){
                temp_date = 31;
                if(month == 1){             // ngày đầu năm
                    temp_month = 12;
                    temp_year--;
                }else{
                    temp_month--;
                }
            }else{
                temp_date--;
            }
            str_date = to_string(temp_date);
            str_month = to_string(temp_month);
            if(temp_date < 10){
                str_date = '0' + str_date;
            }
            if(temp_month < 10){
                str_month = '0' + str_month;
            }
            cout << "The next day: " << str_date << '/' << str_month << '/' << temp_year << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}