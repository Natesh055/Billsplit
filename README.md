Overview
The Group Expense Manager is a C++ program that helps manage and settle shared expenses among a group of people. The program tracks individual payments made by each person for various occasions and calculates how much each person owes or is owed. It then generates the necessary transactions to settle the debts among the group members.



Features
Dynamic Entry of Group Members: Users can input the names of all participants involved in the shared expenses.
Occasion-Based Expense Tracking: For each occasion, users can input the total amount paid by each person and specify for whom the payment was made.
Comprehensive Expense Calculation: The program calculates the net balance for each participant and identifies who owes money and who should receive money.
Automated Transaction Generation: The program generates a list of transactions that need to be made to settle all debts within the group.
How It Works
Input Phase:

Enter the names of all group members.
Specify the number of occasions for which payments were made.
For each occasion, enter the payment details including the total amount paid by each person and for whom the payment was made.
Calculation Phase:

The program calculates the net balance for each participant based on their payments and the amount received on their behalf.
It then categorizes participants into debtors (those who owe money) and creditors (those who are owed money).
Settlement Phase:

The program generates a list of transactions where debtors transfer money to creditors to settle all debts.












Example

Enter Number of persons:
3

Enter First Name of 1:
Alice

Enter First Name of 2:
Bob

Enter First Name of 3:
Charlie

Enter number total number of occasions which required payments:
2

Enter Occasion 1:
Dinner

Enter the payment details for Dinner
Enter Total amount payed by Alice:
300

Enter Number associated for the person payed for, -1 if not payed for anyone
1

Enter amount payed for Bob:
150

Enter Number associated for the person payed for, -1 if not payed for anyone
2

Enter amount payed for Charlie:
100

Enter Total amount payed by Bob:
200

...

Transactions to settle the debts:
Charlie would receive 50 Rupees from Alice
Bob would receive 50 Rupees from Alice
