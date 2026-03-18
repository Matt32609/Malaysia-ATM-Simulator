# Malaysia-ATM-Simulator
A command-line ATM simulator built in Python that mimics real Malaysian banking interactions such as withdrawals, deposits, and PIN authentication.

This project was created to strengthen my understanding of Python concepts including input validation, error handling, global variables, and clean program structure.

Key features of the code:
------------------------------------------------------------------------------------

1. Secure Authentication: 
- A PIN-based login system that tracks attempts. If the user enters the wrong PIN 3 times, the account is locked and the program exits.
 

2. Account Management:
- The simulator includes a "Change PIN" feature that requires the original PIN for verification and double-checks the new PIN before saving.


3. Simulator Tools:
- A unique "Factory Reset" option specifically for this simulator that restores the default balance and PIN instantly.


4. Graceful Error Handling:
- Instead of letting the program crash with code errors , I used try-except blocks to catch mistakes and provide helpful, human-readable instructions on how to fix them.


5. Currency denomination adjustments:
- I used specific text formatting (like RM{balance:.2f}) to ensure currency always looks professional and realistic, mirroring a real Malaysian ATM screen.


6. Smart Validation:
- I implemented mathematical checks such as (round(oa * 100) % 5 == 0) to ensure users only interact with valid Malaysian currency denominations, preventing unrealistic transactions.


7. Efficient Input Selection:
- Instead of using long chains of if/else statements for withdrawals selection menu , I implemented Python Dictionaries to map menu numbers directly to RM values.

To use this simulator:
----------------------------------------------------------------------------------
- Default PIN number : 123456
- Default balance : RM1000.00
(the balance and pin number is able to change throughout the session)

To run the simulator:
----------------------------------------------------------------------------------

- chmod +x atm\ simulator.py
- ./atm\ simulator.py

Example of images:
-----------------------------------------------------------------------------------


<img width="562" height="338" alt="MINGW64__c_Users_Matthew Kam_Desktop_R 18_03_2026 12_08_35" src="https://github.com/user-attachments/assets/4c2299d4-a689-4977-a230-fc545449138f" />


What I learnt throughout the project:
------------------------------------------------------------------------------
- Handling user input and edge cases

- Structuring Python applications logically

- Implementing basic security features

- Using dictionaries for cleaner code design


