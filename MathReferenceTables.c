#include <stdio.h>
#include <math.h>

#define TABLE_SIZE 20
#define START_SIDE 3
#define MAX_SIDE 40
#define MAX_DECIMAL_NUMBER 128
#define UPPER_LIMIT_PRIME 1000

//PROTOTYPES
void initialise(int tableArray[TABLE_SIZE][TABLE_SIZE], int a1[MAX_DECIMAL_NUMBER]);
void printTable(int a[TABLE_SIZE][TABLE_SIZE]);
void polygonSideAngles();
void printBinDecHex();
int decimalToBinary(int number);
void printPrimeNumbers();
void runEratosthenes(int upperBound, int primes[]);

//Global variables
int i, j;
int tableArray[TABLE_SIZE][TABLE_SIZE];
int a1[MAX_DECIMAL_NUMBER];
int primes[UPPER_LIMIT_PRIME];

int main(void) {
	int userChoice;
	char menu[] = "\nEnter a selection or enter [-1] to exit: \n[1] Multiplication Table  (20 x 20) \n[2] Interior Angle of Regular Polygons  \n[3] Binary, Decimal, Hexidecimal Table \n[4] Prime Numbers Less than 1000 \n";
	initialise(tableArray, a1);

	printf("MATH REFERENCE TABLES\n\n");
	printf("%s", menu);
	scanf_s("%d", &userChoice);


	while (userChoice != -1) {
		switch (userChoice) {
		case 1:
			printTable(tableArray);

			printf("%s", menu);
			scanf_s("%d", &userChoice);
			break;

		case 2:
			polygonSideAngles();

			printf("%s", menu);
			scanf_s("%d", &userChoice);
			break;
		case 3:
			printBinDecHex();

			printf("%s", menu);
			scanf_s("%d", &userChoice);
			break;
		case 4:
			printPrimeNumbers();

			printf("%s", menu);
			scanf_s("%d", &userChoice);
			break;
		default:
			puts("Incorrect selection entered.");
			printf("%s", menu);
			scanf_s("%d", &userChoice);
			break;
		}
	}

	return 0;
}

void initialise(int tableArray[TABLE_SIZE][TABLE_SIZE], int a1[MAX_DECIMAL_NUMBER]) {
	//initialise tableArray
	for (size_t i = 1; i <= TABLE_SIZE; i++) {
		for (size_t j = 1; j <= TABLE_SIZE; j++) {
			tableArray[i][j] = i;
		}
	}

	//initialise a1
	for (i = 0; i <= MAX_DECIMAL_NUMBER; i++) {
		a1[i] = i;
	}

	//initialise prime numbers
	runEratosthenes(UPPER_LIMIT_PRIME, primes); //use the sieve of Eratosthenes to find prime numbers

}

void printTable(int tableArray[TABLE_SIZE][TABLE_SIZE]) {
	printf("MULTIPLICATION TABLE (20 X 20)\n\n");

	//print coloumn header
	printf("%4c %2d", '|', 1);
	for (int k = 2; k <= TABLE_SIZE; k++) {
		printf("%4d", k);
	}
	printf("\n-----------------------------------------------------------------------------------\n");

	//print the rest of the table
	for (i = 1; i <= TABLE_SIZE; i++) {
		printf("%2d |", i); //print row classifier
		for (j = 1; j <= TABLE_SIZE; j++) {
			printf("%3d ", i*j); //print body of the table
		}
		puts("");
	}
}

void polygonSideAngles() {
	printf("EACH INTERIOR ANGLE OF REGULAR POLYGONS\n\n");
	double polygonArray[MAX_SIDE];
	for (i = START_SIDE; i <= MAX_SIDE; i++) {
		polygonArray[i - START_SIDE] = i;
	}

	printf("No. of Sides\tEach Interior Angle (Degrees)\n");

	for (i = 0; i <= MAX_SIDE - START_SIDE; i++) {
		double interiorAngle = ((polygonArray[i] - 2) * 180) / polygonArray[i];
		printf("%6.0f %25f\n", polygonArray[i], interiorAngle);
	}

}

void printBinDecHex() {
	printf("BINARY(UNSIGNED), DECIMAL, HEXIDECIMAL TABLE\n\n");

	printf("%-12s %-12s %-12s\n", "Binary", "Decimal", "Hexidecimal");
	for (i = 0; i <= MAX_DECIMAL_NUMBER; i++) {
		printf("%-12.8d %-12d %-12x\n", decimalToBinary(a1[i]), a1[i], a1[i]);
	}
}

int decimalToBinary(int number) {
	int remainder;
	int result = 0, e = 1;
	while (number != 0) {
		remainder = number % 2;
		number = number / 2;
		result = result + (remainder * e);
		e *= 10;
	}
	return result;
}

void printPrimeNumbers() {
	printf("PRIME NUMBERS LESS  THAN 1000\n\n");
	int primes[UPPER_LIMIT_PRIME];
	runEratosthenes(UPPER_LIMIT_PRIME, primes); //use the sieve of Eratosthenes to find prime numbers
	for (i = 0; i < UPPER_LIMIT_PRIME; i++) {
		if (primes[i] == 1) //print all elements that are set to 1 (true)
			printf("%-3d ", i);
	}
	puts("");
}


void runEratosthenes(int upperBound, int primes[]) {
	//set all values to 1 (true)
	for (i = 0; i < upperBound; i++) {
		primes[i] = 1;
	}

	primes[0] = 0, primes[1] = 0;// set 0 and 1 to 0 (false)

								 //set the multiples of i to 0 (false)
	for (i = 2; i < sqrt(upperBound); i++) {
		for (j = i * i; j < upperBound; j += i) {
			primes[j] = 0;
		}
	}
}