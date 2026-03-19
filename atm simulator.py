#!/usr/bin/env python3

pin = 123456
balance = 1000.00

def pin_page():
    try:
        typing = int(input("Hello , please enter your pin number."))
        if typing == pin:
            print("Accepted , onto the main menu now.")
            return True
        elif typing != pin:
            print("Sorry , please try again.")
            return False
    except ValueError:
        print("Sorry , please try again.")
        return False

attempts = 0 

while attempts < 3:
    success = pin_page()
    if success:
        break  
    else:
        attempts = attempts + 1
        remaining = 3 - attempts
        if remaining > 0:
            print(f"You have {remaining} attempts remaining.")
        else:
            print("TOO MANY INCORRECT ATTEMPTS. ACCOUNT LOCKED.")
            exit() 

def atm_menu():
    try:
        global balance
        global pin
        print("Please select a transaction to continue.")
        print("(1) --- Withdrawal")
        print("(2) --- Balance Inquiry") 
        print("(3) --- Change your pin number")
        print("(4) --- Factory reset (SPECIAL FOR THIS ATM SIMULATOR ONLY)")
        print("(5) --- Deposit")
        print("(6) --- Exit")
        selection = int(input("Please type either 1 , 2 , 3 , 4 , 5 or 6 to continue."))
        if selection == 1:
            print("Please select an amount to continue.")
            print("(1) RM100 | (2) RM400 | (3) RM800 | (4) RM1100")
            print("(5) RM1400 | (6) RM1700 | (7) Other amount | (8) Main menu")
            one_input = int(input("Please type either 1 , 2 , 3 , 4 , 5 , 6 , 7 or 8 to continue."))
            amounts = {1: 100, 2: 400, 3: 800, 4: 1100, 5: 1400, 6: 1700}
            if one_input in amounts:
                cash = amounts[one_input] 
                if cash <= balance:
                    balance = round(balance - cash, 2)
                    print("Transaction successful!")
                    print("(1) Yes | (2) No")
                    abcde = int(input(f"Your current balance is RM{balance:.2f} . Would you like to continue the transaction? Please type either 1 or 2 to continue."))
                    if abcde == 1:
                        return
                    elif abcde == 2:
                        print("Thank you for using this ATM.")
                        exit()
                    else:
                        print("Sorry , this was an invalid response . Please try again.")
                        return 
                else:
                    print(f"Insufficient funds! You only have RM{balance:.2f}.")
            elif one_input == 7:
                oa = float(input("Please type your amount: "))
                if 0 < oa <= balance and round(oa * 100) % 5 == 0:
                    balance = round(balance - oa, 2)
                    print("Transaction successful!")
                    print("(1) Yes | (2) No")
                    abcde = int(input(f"Your current balance is RM{balance:.2f} . Would you like to continue the transaction? Please type either 1 or 2 to continue."))
                    if abcde == 1:
                        return
                    elif abcde == 2:
                        print("Thank you for using this ATM.")
                        exit()
                else:
                    print("Invalid amount. You cannot withdraw RM0 , negative amount , unrealistic amounts , amounts exceeding your balance or with excessive decimals.")
                    return 
            elif one_input == 8:
                return 
            else:
                print("Invalid response.")
                return  
        elif selection == 2:
            print(f"Your balance is RM{balance:.2f} . Would you like to continue?")
            print("(1) --- Yes")
            print("(2) --- No")
            balance_select = int(input("Please type either 1 or 2 to continue."))
            if balance_select == 1:
                return
            elif balance_select == 2:
                print("Thank you for using this ATM.")
                exit()
            else:
                print("Sorry , this was an invalid response . Please try again.")
                return 
        elif selection == 3:
            original_pin = int(input("Enter your original pin number . If you wish to return to the main menu , type any number or letter once and you will be returned to the menu. "))
            if original_pin == pin:
                new_pin_input = input("Please enter your desired new pin number (4-6 digits).: ")
                if new_pin_input.isdigit() and 4 <= len(new_pin_input) <= 6:
                    new_pin = int(new_pin_input)
                    confirm_pin = int(input("Please reenter your desired new pin number for verification."))
                    if new_pin == confirm_pin:
                        pin = new_pin
                        print("(1) Yes | (2) No")
                        caa = int(input("Your pin number has been changed . Would you like to continue the transaction? Please type either 1 or 2 to continue."))
                        if caa == 1:
                            return
                        elif caa == 2:
                            print("Thank you for using this ATM.")
                            exit()
                    else:
                        print("Sorry , the verification of the new pin number failed , the pin number will not be changed . Please try again.")
                        return
                else:
                    print("The number of digits was not sufficient . Please try again.") 
            else:
                print("Incorrect pin number.")
                return 
        elif selection == 4:
            balance = 1000.00
            pin = 123456
            print("System fully reset.")
            print("(1) Yes | (2) No")
            fffff = int(input("Would you like to try the simulator again? Please type either 1 or 2 to continue."))
            if fffff == 1:
                return
            else:
                print("Thank you for using this ATM.")
                exit()
        elif selection == 5:
            akaun = int(input("Please enter your account number , If you wish to return to the main menu , type any number or letter once and you will be returned to the menu.:"))
            nas = 1234567890
            if akaun == nas:
                print("Account number verified.")
            else:
                print("Wrong account number.")
                return
            dep = float(input("Enter the amount you would like to deposit."))
            if dep > 0 and round(dep * 100) % 5 == 0:
                balance = round(balance + dep, 2)
                print(f"Success! RM{dep} has been added to your account.")
                print(f"New balance: RM{balance:.2f}")
                print("(1) Yes | (2) No")
                cont = int(input("Would you like to continue the transaction? "))
                if cont == 2:
                    print("Thank you for using this ATM.")
                    exit()
            else:
                print("Invalid amount. You cannot deposit RM0 , negative amounts , unrealistic amounts or amounts that contains excessive decimals.")
                return
        elif selection == 6:
            print("Thank you for using this ATM.")
            exit()
    except ValueError:
        print("Sorry , this was an invalid response . Please try again.")
        return 
while True:
    atm_menu()



        
            
    
