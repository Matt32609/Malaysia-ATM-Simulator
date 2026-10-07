#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int ask_to_exit(void);
int pinpage(void);
int atmmenu(void);
int withdrawal(void);
int binq(void);
int changepin(void);
int deposit(void);

void save_bank_data(void);
void load_bank_data(void);

double balance = 1000.00;
int pin = 123456;

void load_bank_data(void)
    {FILE *f = fopen("bank_data.json", "r");
    int check1;
    int check2;

    if (f != NULL)
        {fscanf(f, "{\n");
        check1 = fscanf(f, "\"pin\": %d,\n", &pin);
        check2 = fscanf(f, "\"balance\": %lf\n", &balance);
        fscanf(f, "}\n");

        if (check1 != 1 || check2 != 1)
            {pin = 123456;
            balance = 1000.00;}

        fclose(f);}

    else
        {pin = 123456;
        balance = 1000.00;
        save_bank_data();}}

void save_bank_data(void)
    {FILE *f = fopen("bank_data.json", "w");
    if (f != NULL)
        {fprintf(f, "{\n");
        fprintf(f, "\"pin\": %d,\n", pin);
        fprintf(f, "\"balance\": %.2f\n", balance);
        fprintf(f, "}\n");

        fclose(f);}}

int ask_to_exit(void)
    {char exittask[20];
    int input;

    while (1)
        {printf("(1) Yes | (2) No\n");
        printf("Do you wish to continue? Enter either '1' or '2' to continue.\n");fgets(exittask, sizeof(exittask), stdin);
        if (exittask[0] == '\n')
            {printf("Invalid response.\n");
            continue;}
        if (sscanf(exittask, "%d", &input) != 1)
            {printf("Invalid response.\n");
            continue;}

        if (input == 1)
            {return 1;}
        else if (input == 2)
            {return 0;}
        else
            {printf("Invalid response.\n");
            continue;}}}
    
int pinpage(void)
    {char pininput[20];
    int typing;
    int attempt = 0;
    int remaining;
    
    while (attempt < 3)
        {printf("Hello. Please enter your PIN.\n");fgets(pininput, sizeof(pininput), stdin);
        
        if (pininput[0] == '\n')
            {printf("Invalid response.\n");
            continue;}
        else if (sscanf(pininput, "%d", &typing) != 1)
            {printf("Invalid response.\n");
            attempt = attempt + 1;}
        
        else if (typing == pin)
            {return 1;}
        else 
            {printf("Incorrect PIN number.\n");
            attempt = attempt + 1;}
        
        if (attempt < 3)
            {remaining = 3 - attempt;
            printf("You have %d attempts left.\n", remaining);}}
    printf("Your account has been locked. Please seek your bank for assistance.\n");
    return 0;}
            
            
int atmmenu(void)
    {char menuselect[20];
    int input;

    while (1)
        {printf("(1) Withdrawal | (2) Balance Inquiry | (3) Change PIN | (4) Factory reset (SPECIAL FOR THIS SIM ONLY) | (5) Deposit | (6) Return card\n");
        printf("Please enter a digit either 1, 2, 3, 4, 5 or 6 to continue.\n");fgets(menuselect, sizeof(menuselect), stdin);

        if (menuselect[0] == '\n')
            {printf("Invalid response.\n");
            continue;}
        if (sscanf(menuselect, "%d", &input) != 1)
            {printf("Invalid response.\n");
            continue;}

        if (input == 1)
            {if (withdrawal() == 0)
                {return 0;}}
        else if (input == 2)
            {if (binq() == 0)
                {return 0;}}
        else if (input == 3)
            {if (changepin() == 0)
                {return 0;}}
        else if (input == 4)
            {balance = 1000.00;
            pin = 123456;
            save_bank_data();
            printf("System fully reset.\n");

            if (ask_to_exit() == 1)
                {continue;}
            else
                {printf("Thank you for using this ATM.\n");
                return 0;}}
        else if (input == 5)
            {if (deposit() == 0)
                {return 0;}}
        else if (input == 6)
            {printf("Thank you for using this ATM\n");
            return 0;}
        else
            {printf("Invalid response.\n");}}}

int withdrawal(void)
    {char withselect[20];
    int input;
    
    while (1)
        {printf("(1) RM100 | (2) RM400 | (3) RM800 | (4) RM1100\n");
        printf("(5) RM1400 | (6) RM1700 | (7) Other amount | (8) Main Menu\n");
        printf("Please enter a digit from 1 to 8 to continue.\n");fgets(withselect, sizeof(withselect), stdin);

        if (withselect[0] == '\n')
            {printf("Invalid response\n");
            continue;}
        
        if (sscanf(withselect, "%d", &input) != 1)
            {printf("Invalid response\n");
            continue;}

        int amount[] = {0, 100, 400, 800, 1100, 1400, 1700};
        
        if (input >= 1 && input <= 6)
            {int cash = amount[input];
            if (cash <= balance)
                {balance = round((balance - cash) * 100.0) / 100.0;
                save_bank_data();
                printf("Please collect your cash.\n");

                if (ask_to_exit() == 1)
                    {return 1;}
                else
                    {printf("Thank you for using this ATM.\n");
                    return 0;}}
            else
                {printf("Insufficient funds.\n");
                if (ask_to_exit() == 1)
                    {return 1;}
                else
                    {printf("Thank you for using this ATM.\n");
                    return 0;}}}
        
        else if (input == 7)
            {double oa;
            char otheramount[20];
            
            while (1)
                {printf("Please enter your desired amount.\n");fgets(otheramount, sizeof(otheramount), stdin);
                
                if (otheramount[0] == '\n')
                    {printf("Invalid response.\n");
                    return 1;}
                
                if (sscanf(otheramount, "%lf", &oa) != 1)
                    {printf("invalid response.\n");
                    return 1;}

                if ((oa > 0 && oa <= balance) && (fmod(oa * 100, 5.0) == 0.0))
                    {balance = round((balance - oa) * 100.0) / 100.0;
                    save_bank_data();
                    printf("Please collect your cash.\n");

                    if (ask_to_exit() == 1)
                        {return 1;}
                    else
                        {printf("Thank you for using this ATM.\n");
                        return 0;}}
                else
                    {printf("Invalid amount. You cannot withdraw RM0 , negative amount , unrealistic amounts , amounts exceeding your balance or with excessive decimals.\n");
                    continue;}}}
        else if (input == 8)
            {return 1;}
        else
            {printf("Invalid response\n");}}}

int binq(void)
    {printf("Your balance is RM%.2f\n", balance);
    
    if (ask_to_exit() == 1)
        {return 1;}
    else
        {printf("Thank you for using this ATM.\n");
        return 0;}}

int changepin(void)
    {int original_pin;
    int new_pin;
    int confirm_pin;
    char originalinput[20];
    char newpininput[20];
    char confirminput[20];

    while (1)
        {printf("Enter your original PIN.\n");fgets(originalinput, sizeof(originalinput), stdin);
        
        if (originalinput[0] == '\n')
            {printf("Invalid response\n");
            return 1;}
        
        if (sscanf(originalinput, "%d", &original_pin) != 1)
            {printf("Invalid response\n");
            return 1;}
        
        if (original_pin == pin)
            {printf("Please enter your desired new PIN (4-6 digits).\n");fgets(newpininput, sizeof(newpininput), stdin);
            newpininput[strcspn(newpininput, "\n")] = '\0';

            if (strlen(newpininput) < 4 || strlen(newpininput) > 6)
                {printf("The number of digits was insufficient or excessive. Please try again.\n");
                return 1;}
            
            for (int i = 0; newpininput[i] != '\0'; i = i + 1)
                {if (!isdigit(newpininput[i]))
                    {printf("PIN must contain digits only.\n");
                    return 1;}}

            sscanf(newpininput, "%d", &new_pin);
                
            printf("Please reenter your desired new PIN for verification.\n");fgets(confirminput, sizeof(confirminput), stdin);

            if (sscanf(confirminput, "%d", &confirm_pin) != 1)
                {printf("Invalid response.\n");
                return 1;}

            if (new_pin == confirm_pin)
                {pin = new_pin;
                save_bank_data();
                printf("Your PIN has been changed successfully.\n");
            
                if (ask_to_exit() == 1)
                    {return 1;}
                else
                    {printf("Thank you for using this ATM.\n");
                    return 0;}}
            else
                {printf("PIN confirmation failed. PIN will not be changed.\n");
                return 1;}}
        else
            {printf("Incorrect PIN number.\n");
            return 1;}}}

int deposit(void)
    {char noakaun[] = "1234567890";
    char akaun[20];
    double running_total = 0.00;
    char deposit[20];
    double amount;
    int input2;
    char option[20];

    while (1)
        {printf("Please enter your account number.\n");fgets(akaun, sizeof(akaun), stdin);
        akaun[strcspn(akaun, "\n")] = '\0';

        if (akaun[0] == '\0')
            {printf("Invalid response.\n");
            return 1;}
        
        if (strcmp(akaun, noakaun) != 0)
            {printf("Invalid response.\n");
            return 1;}

        while (1)
            {printf("Enter the amount you would like to deposit.\n");fgets(deposit, sizeof(deposit), stdin);

            if (deposit[0] == '\n')
                {printf("Invalid response.\n");
                return 1;}
            
            if (sscanf(deposit, "%lf", &amount) != 1)
                {printf("Invalid response.\n");
                return 1;}
            
            if ((amount > 0) && (fmod(amount * 100, 5.0) == 0))
                {running_total = round((running_total + amount) * 100.0) / 100.0;

                while (1)
                    {printf("(1) Add amount | (2) Yes | (3) No\n");    
                    printf("Your intended deposit amount is : RM%.2f. Would you like to proceed?\n", running_total);
                    printf("Please enter either 1 , 2 or 3 to continue.\n");fgets(option, sizeof(option), stdin);

                    if (option[0] == '\n')
                        {printf("Invalid response.\n");
                        continue;}
                
                    if (sscanf(option, "%d", &input2) != 1)
                        {printf("Invalid response.\n");
                        continue;}

                    if (input2 == 1)
                        {break;}
                    else if (input2 == 2)
                        {balance = round((balance + running_total) * 100.0) / 100.0;
                        save_bank_data();
                        printf("Transaction successful!\n");       
                        if (ask_to_exit() == 1)
                            {return 1;}
                        else
                            {printf("Thank you for using this ATM.\n");
                            return 0;}}
                    else if (input2 == 3)
                        {printf("Your deposit amount has been returned.\n");
                        return 1;}}}
            else
                {printf("Invalid amount. You cannot deposit RM0 , negative amounts , unrealistic amounts or amounts that contains excessive decimals.\n");
                continue;}}}}

int main(void)
    {load_bank_data();

    if (pinpage() == 1)
        atmmenu();

    return 0;}



                    
                    
        
                

            
                


        
    
            
            
        