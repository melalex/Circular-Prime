#define _SCL_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define N 1'000'000
using namespace std;

vector<int> *sieveOfEratosthenes()
{
	bool sieve[N+1];
	fill_n(begin(sieve), N+1, true);
	vector<int> *primeNumbers = new vector<int>();
	for (int i = 2; i <= N; i++)
	{
		if (sieve[i])
		{
			primeNumbers->push_back(i);
			for (int j = i; j <= N; j += i)
				sieve[j] = false;
		}

	}
	return primeNumbers;
}

int circularShift(int numb, int length)
{
	int first = numb / pow(10, length - 1),
		tail = numb % (int)pow(10, length - 1);

	return tail * 10 + first;
}

bool consistOf1379(int numb, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		numb = circularShift(numb, length);
		if (numb % 10 != 1 && numb % 10 != 3 && numb % 10 != 7 && numb % 10 != 9)
			return false;
	}
	return true;
}

int amountOfCircularPrime()
{
	vector<int> *primeNumbers = sieveOfEratosthenes();
	int amount = primeNumbers->size(), 
		newNumber,
		length;
	
	for (int number : *primeNumbers)
	{
		length = log10(number) + 1;
		if (consistOf1379(number, length))
		{
			newNumber = number;
			for (int i = 0; i < length - 1; i++)
			{
				newNumber = circularShift(newNumber, length);
				if (find(primeNumbers->begin(), primeNumbers->end(), newNumber) == primeNumbers->end())
				{
					amount--;
					break;
				}
			}
			
		}
		else
		{
			amount--;
		}

	}

	delete primeNumbers;
	return amount;
}

int main()
{
	cout << amountOfCircularPrime() <<endl;
	system("PAUSE");
	return 0;
}
