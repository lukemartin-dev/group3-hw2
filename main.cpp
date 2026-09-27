#include <iostream>
#include <string>

using namespace std;

//pass in space-delimited arguments when you call the executable
//Example: ./a.out 1 2 3.3
int main( int argc, char * argv[] )
{
	if (argc > 4) 
	{
		cout << "Too many arguments. Cannot pass in more than three." << endl;
		return -1;
	}

	int i = 1;
	double loan_amount, yearly_interest_rate, monthly_payment;

	double arguments [3];

	while ( i < argc )
	{
		try
		{
			arguments[i-1] = stod(argv[i]);
		}
		catch(const std::invalid_argument&)
		{
			if(i==1)
				cout << "(Invalid loan amount): " << argv[i] << endl;
			else if (i==2)
				cout << "(Invalid interest rate): " << argv[i-1] << " " << argv[i] << endl;
			else
				cout << "(Invalid payment): " << argv[i-2] << " " << argv[i-1] << " " << argv[i] << endl;
			return -2;
		}
		i++;
	}

	loan_amount = arguments[0];
	yearly_interest_rate = arguments[1];
	monthly_payment = arguments[2]; 

	// Calculations and Table
	
	double monthly_interest_rate = yearly_interest_rate / 12.0;
	double interestCalc = monthly_interest_rate / 100.0;
	int currentMonth = 0;
	double totalInterest = 0.0;
	
	//Check monthly payment
	if(monthly_payment <= loan_amount * interestCalc) {
		cout << "Error: Monthly payment must be greater than the monthly interest." << endl;
		return -3;
 	}

	// Currency Formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

	//Header
	cout << "****************************************************\n"
	     << "\tAmortization Table\n"
		 << "****************************************************\n"
		 << "Month\tBalance\tPayment\tRate\tInterest\tPrincipal\n";

	while (loan_amount > 0) {
		if (currentMonth == 0) 
		{
			cout << currentMonth++ << "\t$" << loan_amount;
			if (loan_amount < 1000) cout <<"\t";
			cout << "\tN/A\tN/A\tN/A\tN/A\n";
		}
		else 
		{
			double monthly_interest = loan_amount * interestCalc;
			double actual_payment;
			double principal;

			if (loan_amount * (1.0 + interestCalc) < monthly_payment) {
				actual_payment = loan_amount + monthly_interest;
				principal = loan_amount;
				loan_amount = 0.0;
			} else {
				actual_payment = monthly_payment;
				principal = monthly_payment - monthly_interest;
				loan_amount -= principal;
			}

			totalInterest += monthly_interest;

			cout << currentMonth++ << "\t$" << loan_amount;
			if (loan_amount < 1000) cout << "\t";
			cout << "\t$" << actual_payment
				<< "\t" << monthly_interest_rate
				<< "\t$" << monthly_interest
				<< "\t\t$" << principal << "\n";
		}
	}
	
	cout << "****************************************************\n";
	cout<< " \nIt takes " << --currentMonth << " months to pay off the loan.\n"
	<< "Total interest paid is: $" << totalInterest << endl << endl;
	
	return 0;
}
