#include<stdio.h>
#include<string.h>

int get_century_code(int);

int calculations_to_get_doomsday(int, int);

int get_date_code(int, int, int, int);

int check_leapyear(int);

int find_weekday_of_first_date_of_month(int, int, int);

int get_month_days(int, int);

int main()
{
    char weekdays[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    char month_name[12][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    
    int month, year;

    fflush(stdin);
    printf("\n\nWELCOME!!");
    printf("\nEnter the month(in months) --> ");
    scanf("%d", &month);
    printf("\nEnter the year(1500 - 3999) --> ");
    scanf("%d", &year);

    int date = 1;
    int final_result = find_weekday_of_first_date_of_month(date, month, year);

    FILE *pointer = NULL;
    pointer = fopen("calendar_of_any_one_month_of_any_year.txt", "w");

    fprintf(pointer, "MONTH \t --> %s \nYEAR \t --> %d", month_name[month-1], year);
    fprintf(pointer, "\n------------------------------\n");

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fprintf(pointer, "%c", weekdays[i][j]);
        }
        fprintf(pointer, "\t");
        
    }
    
    fprintf(pointer, "\n");

    int number = 0;
    for (int i = 0; i < final_result; i++)
    {
        fprintf(pointer, "   \t");
    }

    int new_line_maker = final_result; // to adjust the first row
    
    int month_days = get_month_days(month, year);

    for (int i = 1; i <= month_days; i++)
    {
        fprintf(pointer, "%3d\t", i);
        new_line_maker++;
        if (new_line_maker >= 7)
        {
            new_line_maker = 0;
            fprintf(pointer, "\n");
        }
        
    }

    fclose(pointer);
    
    return 0;
}


int find_weekday_of_first_date_of_month(int date, int month, int year)
{
    int century_of_year = (year/100)*100;

    int century_code = get_century_code(century_of_year);

    int last_two_digits_of_year = year - century_of_year;

    int result = calculations_to_get_doomsday(last_two_digits_of_year, century_code);
    // here result is the remainder when the sum is divided by 7 and the remainder is the date code of the doomsday of the year

    int final_remainder = get_date_code(date, month, year, result);

    return final_remainder;
    
}

int get_century_code(int year)
{
    int code;
    switch (year)
    {
        case 1500:
        case 1900:
        case 2300:
        case 2700:
            code = 3;
            break;
        case 1600:
        case 2000:
        case 2400:
        case 2800:
            code = 2;
            break;
        case 1700:
        case 2100:
        case 2500:
        case 2900:
            code = 0;
            break;
        case 1800:
        case 2200:
        case 2600:
        case 3000:
            code = 5;
            break;

        default: printf("\nYour year must be from 1500 upto 3000");
    }

    return code;
}


int calculations_to_get_doomsday(int two_digits, int code)
{
    int quotient_1 = two_digits / 12;
    int remainder = two_digits % 12;
    int quotient_2 = 0;
    if (remainder >= 4)
    {
        quotient_2 = remainder / 4;
    }

    int sum = code + quotient_1 + remainder + quotient_2;

    int remainder_2 = sum % 7;
    
    return remainder_2;

}


int get_date_code(int date, int month, int year, int remainder) // at the place of remainder, the remainder when the sum was divided by 7 in the function calculations_to_get_doomsday is expected. the remainder is also the date code of the doomsday of the year concerned
{
    int leapyear_code_result = check_leapyear(year), base_date;

    switch (month)
    {
    case 1:
        (leapyear_code_result == 0) ? (base_date = 3) : (base_date = 4);
        break;
    case 2:
        (leapyear_code_result == 0) ? (base_date = 28) : (base_date = 29);
        break;
    case 3:
        base_date = 14;
        break;
    case 4:
        base_date = 4;
        break;
    case 5:
        base_date = 9;
        break;
    case 6:
        base_date = 6;
        break;
    case 7:
        base_date = 11;
        break;
    case 8:
        base_date = 8;
        break;
    case 9:
        base_date = 5;
        break;
    case 10:
        base_date = 10;
        break;
    case 11:
        base_date = 7;
        break;
    case 12:
        base_date = 12;
        break;
    }

    if (date > base_date)
    {
        for (int i = (base_date + 1); i <= date; i++)
        {
            remainder++;
        }
        remainder = remainder % 7;
    }
    if (date < base_date)
    {
        for (int i = (base_date - 1); i >= date; i--)
        {
            (remainder-1 >= 0) ? (remainder--) : (remainder = 6);
            // so whenever the remainder is becoming negative, we are making it 6 again, otherwise we are letting it decrease 
        }
    }
    
    // if asked date and base date are same, the remainder remains same
    
    return remainder;
    
}


int check_leapyear(int year)
{
    int leapyear_code;
    
    if (year % 4 != 0)
    {
        leapyear_code = 0;
    }
    else if (year % 100 != 0)
    {
        leapyear_code = 1;
    }
    else if (year % 400 != 0)
    {
        leapyear_code = 0;
    }
    else
    {
        leapyear_code = 1;
    }

    return leapyear_code;
}


int get_month_days(int month, int year)
{
    int month_days;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        month_days = 31;
        break;
    case 2:
        int leapyear_result = check_leapyear(year);
        (leapyear_result == 0) ? (month_days = 28) : (month_days = 29);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        month_days = 30;
        break;
    }
    
    return month_days;
}