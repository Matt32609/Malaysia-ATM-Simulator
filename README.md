# Malaysia ATM Simulator
A command-line ATM simulator built in Python that mimics real Malaysian banking interactions such as withdrawals, deposits, and PIN authentication.

This project was created to strengthen my understanding of Python concepts including input validation, error handling, global variables, and clean program structure.

Key features of the code:
------------------------------------------------------------------------------------

1. Secure Authentication: 
- A PIN-based login system that tracks login attempts. If the user enters the wrong PIN 3 times, the account is locked and the program exits.

 

2. Account Management:
- The simulator includes a "Change PIN" feature that requires the original PIN for verification and verifies the new PIN before saving.



3. Simulator Tools:
- A unique "Factory Reset" option  that restores the default balance and PIN instantly.



4. Graceful Error Handling:
- Instead of letting the program crash with errors , I used try-except blocks to catch mistakes and provide helpful, human-readable instructions on how to fix them.



5. Currency denomination adjustments:
- I used formatted outputs like (RM{balance:.2f}) to ensure currency always looks professional and realistic, mirroring a real Malaysian ATM screen.



6. Smart Validation:
- I implemented mathematical checks such as (round(oa * 100) % 5 == 0) / (fmod(oa * 100, 5.0) == 0.0) to ensure users only interact with valid Malaysian currency denominations, preventing unrealistic transactions.



7. Efficient Input Selection:
- Instead of using long chains of if/else statements for the withdrawal selection menu , I implemented Python Dictionaries to map menu numbers directly to RM values.


8. Strict PIN Validation:
- I implemented dual-layer validation using isdigit() and len() to ensure new PINs consist strictly of numbers and meet the 4-6 digit security standard, preventing system crashes and invalid data entries.


9. Centralized Navigation Control:
- Instead of repeating the same "continue" question in every menu after a successful transaction , I moved it into its own dedicated function called "ask_to_exit()" . This allows the program to jump to that logic from any transaction and return, making the code much cleaner and easier to manage.


10. Smart Cash Accumulation:
- I used a while loop and the "continue" command in the deposit section so the machine remembers the previous amounts inserted. This allows a user to keep adding cash (e.g., RM123 + RM123) to reach a total of RM246 before finalizing the deposit transaction.

11.Persistent Data Storage: (NEW ADDITION)
- The simulator utilizes a JSON file system to ensure data persistence. By saving the balance and PIN to an external file, the program retains all account changes even after it is closed, rather than reverting to default values upon every restart.

To use this simulator:
----------------------------------------------------------------------------------
- Default PIN number : 123456
- Default balance : RM1000.00
- Account number : 1234567890 

(The balance and PIN can be changed throughout the session.)
(All bank information are strictly fictional and it is not relevant with real life)

To run the simulator:
----------------------------------------------------------------------------------
PYTHON
- chmod +x atm_simulator.py
- ./atm_simulator.py

C
- gcc atm.c -o atm
- ./atm.exe

Example of images:
-----------------------------------------------------------------------------------

<img width="562" height="380" alt="MINGW64__c_Users_Matthew Kam_Desktop_R 30_03_2026 17_34_30" src="https://github.com/user-attachments/assets/e3f9567d-c89c-4566-87ab-1a4d34be9a74" />








