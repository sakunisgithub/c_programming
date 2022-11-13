#include<stdio.h>

int get_century_code(int);

int calculations_to_get_doomsday(int, int);

int get_date_code(int, int, int, int);

int check_leapyear(int);

void print_output(int);

int main()
{
    int date, month, year;
    printf("WELCOME!!\n\n");
    printf("Get the weekday of any date from year 1500 to year 3999\n");
    printf("\nEnter the date :: \n");
    printf("\nEnter date --> ");
    scanf("%d", &date);
    printf("\nEnter month(in numbers) --> ");
    scanf("%d", &month);
    printf("\nEnter year --> ");
    scanf("%d", &year);

    int century_of_year = (year/100)*100;

    int century_code = get_century_code(century_of_year);

    int last_two_digits_of_year = year - century_of_year;

    int result = calculations_to_get_doomsday(last_two_digits_of_year, century_code);
    // here result is the remainder when the sum is divided by 7 and the remainder is the date code of the doomsday of the year

    int final_remainder = get_date_code(date, month, year, result);

    print_output(final_remainder);
    
    return 0;
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


void print_output(int remainder)
{
    switch (remainder)
    {
    case 0:
        printf("\nSunday");
        break;
    case 1:
        printf("\nMonday");
        break;
    case 2:
        printf("\nTuesday");
        break;
    case 3:
        printf("\nWednesday");
        break;
    case 4:
        printf("\nThursday");
        break;
    case 5:
        printf("\nFriday");
        break;
    case 6:
        printf("\nSaturday");
        break;
    }
}