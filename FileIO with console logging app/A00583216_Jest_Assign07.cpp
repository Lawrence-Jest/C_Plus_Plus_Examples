//
// Calculate gross pay, net pay, pension and deductions for employees of Rogers Hostpital Supplies Company.
//
// Bob Langelaan, lawrence Jest_A00583216
// March 9, 2015, march 10, 2018
//
                                                                                   
#include <iostream>
#include <iomanip>
#include <conio.h>  // Required for _getch() function
#include <fstream>  // Required for file input/output


using namespace std;

//global constants

// One way to specify a file name:
const char * IN_FILE = "EmployeePayInput.txt";

// A second way to specify a file name:
#define OUT_FILE "EmployeePayOutput.txt"

//function prototypes
double calculateGrossPay(double hoursWorked, double payRate); // function prototype for calculateGrossPay
double calculateDeductions(double grossPay, int exemptions, double pensionDeducted);// Function prototype for calculateDeductions
double calculatePension(double grossPay); // Function prototype for calculatePension
double calculateNetPay(double grossPay, double deductions); // Function prototype for calculateNetPay

//static constants
static const int SOCIAL_INSURANCE_NUM_LENGTH = 9; // length of socila insurance number
static const int AMOUNT_TO_DIVIDE_BY = 10; // variable to divide the social insurance number by to check length
static const double MAXIMUM_HOURLY_WAGE = 99.99; // maximum hourly wage
static const int MAXIMUM_NUMBER_OF_EXCEPTIONS = 20; // maximum number of exemptions 
static const double MAXIMUM_HOURS_BEFORE_OVERTIME = 54.0; // maximum number of hours before overtime starts
static const double STANDARD_HOURS_WORKED_WEEKLY = 40.00; // standard work week hours
static const double OVERTIME_PAY_RATE = 1.5; // rate of pay for overtime hours
static const double AMOUNT_TO_TIMES_EXEMPTION = 14.0; //amount to times exemption by
static const double AMOUNT_TO_MINUS_TAXABLE_AFTER_EXEMPTION = 11.0; // Amount to minus after exemption calculation for taxable total calculation
static const double AMOUNT_TO_TIMES_TAXABLETOTAL = 0.00023; // Amount to times taxable total by in federal tax calculation
static const double AMOUNT_TO_ADD_TO_TAXABLETOTAL = 0.14; // Amount to add to taxable total in federal tax calculation
static const double AMOUNT_TO_TIMES_FEDERALTAX_BY = 0.35; // Amount to times federal tax by for prvincial tax calculation
static const double AMOUNT_TO_TAX_GROSSPAY_BY_FOR_PENSION = 0.077; // Amount to tax gross pay by for pension calculation
static const double MAXIMUM_PENSION_DEDUCTION = 16.50; // total amout for pension contribution

int main()
{

	//Declare variables
	long socialInsuranceNum;  // Will store social security number of employee
	int numberOfExemptions,	  // Will store number of excemptions for employee
		counterForEmployeesProcessed = 0; //will store number of employees processed

	double payRate,			// Will store the pay rate for the employee
		hoursWorked,		// Will store hours worked for the employee
		grossPay,			// Will store grossPay for the employee
		deductions,			// Will store deductions for the employee
		pension,			// Will store pension for the employee
		netPay,				// Will store netPay for the employee
		totalNetPay = 0,		// Will store total netPay
		totalGrossPay = 0,		// Will store total grossPay 
		totalPension = 0,		// Will store total pension
		totalDeductions = 0;	// Will store total deductions

	bool socialInsuranceNumChecked = false; // Will store check for valid socialInsuranceNum
	bool numberOfExemptionsChecked = false; // Will store check for numberOfExemptions
	bool payRateChecked = false;			// Will store check for payRate
	bool hoursWorkedChecked = false;		// Will store check for hoursWorked
	
	//Define ifstream object and open file
	ifstream ins;
	ins.open(IN_FILE);

	//Check that file opened without any issues
	if (ins.fail())
	{
		cerr << "ERROR--> Unable to open input file : " << IN_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -1; //error return code
	}

	//Define ofstream object and open file
	ofstream outs;
	outs.open(OUT_FILE);

	//Check that file opened without any issues
	if (outs.fail())
	{
		cerr << "ERROR--> Unable to open output file : " << OUT_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -2; //error return code
	}

	// Read in first social security number
	ins >> socialInsuranceNum;

	//header and column names
	outs << "Rogers Hospital Supplies Company" << "\n" << "----------------------------------" << endl;
	outs << "Social insurance no." << setw(15) << "gross pay" << setw(10) << "net pay" << setw(10) << "pension" << setw(15) << "deductions" << endl;
	outs << "----------------------------------------------------------------------" << endl;


	// Process data until end of file is reached
	while (!ins.eof()){

		// Read in other data for the employee
		ins >> payRate >> numberOfExemptions >> hoursWorked;	
		
		int counterForSocialInsuranceNumberLength = 0; // Will store counter for length of social insurance number

		long socialInsuranceNumberCheck = socialInsuranceNum;//use a long so as not to overwrite the actual social insurance number

		//socialInsuranceNumber should be SOCIAL_INSURANCE_NUM_LENGTH characters so didvide by AMOUNT_TO_DIVIDE_BY and count the divides
		while (socialInsuranceNumberCheck)//check scoialInsuranceNum
		{
			socialInsuranceNumberCheck = socialInsuranceNumberCheck / AMOUNT_TO_DIVIDE_BY;

			++counterForSocialInsuranceNumberLength;
		}

		//socialInsuranceNumber check if/else
		if (counterForSocialInsuranceNumberLength == SOCIAL_INSURANCE_NUM_LENGTH)//valid socialInsuranceNum should be SOCIAL_INSURANCE_NUM_LENGTH
		{
			socialInsuranceNumChecked = true;//passed check
		}
		else
		{
			cerr << left << setw(15) << socialInsuranceNum << setw(15) << " INPUT DATA ERROR:  " << "Invalid social security #" << endl;
			socialInsuranceNumChecked = false;
		}
		
		//payrate check if/else
		if (payRate >= 0.0 && payRate <= MAXIMUM_HOURLY_WAGE)//check payRate 
		{
			payRateChecked = true;//passed check
		}
		else
		{
			cerr << left << setw(15) << socialInsuranceNum << setw(15) << " INPUT DATA ERROR:  " << "Invalid pay rate: "  << fixed << setprecision(2) << payRate << endl;
			payRate = 0.0;
			payRateChecked = false;
			
		}

		//numberOfExemptions check if/else
		if (numberOfExemptions >= 0 && numberOfExemptions < MAXIMUM_NUMBER_OF_EXCEPTIONS) //check numberOfExemptions
		{
			numberOfExemptionsChecked = true; //passed check
		}
		else 
		{
			cerr << left << setw(15) << socialInsuranceNum << setw(15) << " INPUT DATA ERROR:  " << "Invalid number of exemptions: " << numberOfExemptions << endl;
			numberOfExemptions = 0;
			numberOfExemptionsChecked = false;

		}

		//hoursWorked check if/else
		if (hoursWorked >= 0.0 && hoursWorked <= MAXIMUM_HOURS_BEFORE_OVERTIME)
		{
			hoursWorkedChecked = true; //passed check
		}
		else
		{
			cerr << left << setw(15) << socialInsuranceNum << setw(15) << " INPUT DATA ERROR:  " << "Invalid hours worked: " <<  hoursWorked << endl;
			hoursWorkedChecked = false;
		}

		//output to text if all checks passed
		if (socialInsuranceNumChecked == true)
		{
			if (numberOfExemptionsChecked == true)
			{
				if (payRateChecked == true)
				{
					if (hoursWorkedChecked == true)
					{
						grossPay = calculateGrossPay(hoursWorked, payRate);//calcultae grossPay

						totalGrossPay = grossPay + totalGrossPay;//calculate totalGrossPay

						pension = calculatePension(grossPay);//calculate pension contribution

						totalPension = pension + totalPension;//calculate totalPension

						deductions = calculateDeductions(grossPay, numberOfExemptions, pension);//calculate total deductions

						totalDeductions = deductions + totalDeductions;//caalculate totalDeductions

						netPay = calculateNetPay(grossPay, deductions);//calculate netPay

						totalNetPay = netPay + totalNetPay;//calculate totalNetPay

						outs << left << fixed << setprecision(2) << setw(26) << socialInsuranceNum << right << setw(9) << grossPay << setw(10) << netPay
							<< setw(10) << pension << setw(15) << deductions << endl;//output to .txt file
						
						++counterForEmployeesProcessed;

					}
				}
			}
			
		}
		
		
		
		// Read in next social security number
		ins >> socialInsuranceNum;
	}
	
	//summary and display totals
	outs << '\n' << '\n' << "Summary" << '\n' << "--------" << '\n' << endl;
	outs << left << setw(50) << "Number of employees processed:" << setw(30) << counterForEmployeesProcessed << endl;
	outs << left << setw(50) << "Total gross pay for all employees:" << setw(30) << totalGrossPay << endl;
	outs << left << setw(50) << "Total net pay for all employees:" << setw(30) << totalNetPay << endl;
	outs << left << setw(50) << "Total pension withheld for all employees:" << setw(30) << totalPension << endl;
	outs << left << setw(50) << "Total deductions for all employees:" << setw(30) <<
		totalDeductions << endl;


	// Close files
	ins.close();
	outs.close();

	cout << '\n' << endl;	

	_getch(); // causes execution to pause until char is entered

}


//fuction calculateGrossPay to calculate the gross pay of the employee
//double hoursWorked- the hours the emplyee worked
//double payRate- the dollar per hour earned by employee
double calculateGrossPay(double hoursWorked, double payRate)
{
	double grossPay;
	double overtime;
	double overtimePay;
	
	if (hoursWorked <= STANDARD_HOURS_WORKED_WEEKLY)
	{
		grossPay = hoursWorked * payRate;
	}
	else
	{
		overtime = hoursWorked - STANDARD_HOURS_WORKED_WEEKLY;
		overtimePay = overtime * (payRate * OVERTIME_PAY_RATE);
		grossPay = overtimePay + (STANDARD_HOURS_WORKED_WEEKLY  * payRate);
	}
	return grossPay;
}

//function calculateDeductions to calculate the total deductions for the employee
//double grossPay- the grossPay of the employee
//int exemptions- the number of exemptions for employee
//double pensionDeducted- the amount contributed to pension for the employee
double calculateDeductions(double grossPay, int exemptions, double pensionDeducted)
{
	double deductionsTotal = 0;
	double federalTax = 0;
	double taxableTotal = 0;
	double provincialTax = 0;

	taxableTotal = grossPay - (AMOUNT_TO_TIMES_EXEMPTION * exemptions) - AMOUNT_TO_MINUS_TAXABLE_AFTER_EXEMPTION; // taxable total calculation 
	federalTax = taxableTotal * (AMOUNT_TO_ADD_TO_TAXABLETOTAL + (AMOUNT_TO_TIMES_TAXABLETOTAL * taxableTotal)); // federal tax amount calculation
	provincialTax = federalTax * AMOUNT_TO_TIMES_FEDERALTAX_BY; // Provincial tax calculation
	deductionsTotal = federalTax + provincialTax + pensionDeducted;

	if (deductionsTotal > pensionDeducted)
	{
		return deductionsTotal;
	}
	else 
	{
		return pensionDeducted;
	}
}


//function calculatePension to calculate the contribution to the pension of teh employee
//double grossPay-the grossPay of the employee
double calculatePension(double grossPay)
{
	double grossPayPensionCalculation = grossPay * AMOUNT_TO_TAX_GROSSPAY_BY_FOR_PENSION; // pension calculation
	if (grossPayPensionCalculation < MAXIMUM_PENSION_DEDUCTION)
	{
		return grossPayPensionCalculation;
	}
	return MAXIMUM_PENSION_DEDUCTION;
}


//function calculateNetPay to calculate the netPay of the employee
//double grossPay- the gross pay of the employee
//double deductions- the total deductions taken from employees grossPay
double calculateNetPay(double grossPay, double deductions)
{
	double netPayTotal = grossPay - deductions;
	return netPayTotal;
}
