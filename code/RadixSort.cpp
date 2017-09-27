//	numbers[inputs].at(digit)
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

void print(vector<int> numbers[], int inputs) {
	for(int i=0; i<inputs; i++)
	{
	        for(int j=0; j<10; j++)
	        {
	                cout << numbers[i].at(j) << ";";
	                if (j == 9)
	                {
	                        cout << endl;
	                }
		}
	}
}

int findBig(vector<int> numbers[], int inputs) {
	int big = 0;
	for (int i = 0; i < inputs; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(big <= numbers[i].at(j))
			{
				big = numbers[i].at(j);
			}
		}
	}
	return big;
}


void MyFunc (vector<int> numbers[], int inputs ) {
	int digit;
	vector<int> sorted[inputs];
	for (digit = 9; digit >= 0; digit--)
	{
//		int biggest = findBig(numbers,inputs);
		int biggest = 10;
		int C[biggest+1];
		for (int i=0; i<=biggest; i++)
		{
			C[i] = 0;
		}
		for (int j =0; j<inputs; j++)
		{
			C[numbers[j].at(digit)]++;
		}
		for (int k=0;k<=biggest;k++)
		{
			for(int v=0; v<inputs; v++)
			{
				if(numbers[v].at(digit) == k)
				{
					sorted[v] = numbers[v];
				}
			}
		}
	}
	print(sorted, inputs);
}


int main(int argc,char **argv) {

	int inputs;
	cin >> inputs;
	//int* numbers = new int[inputs];
	vector<int> numbers[inputs];
	for ( int i=0; i<inputs; i++ )
	{
		for(int j=0; j<10; j++)
		{
			int num;
			cin >> num;
			numbers[i].push_back(num);
		}
	}
  // Run your algorithms to manipulate the elements in Sequence
	MyFunc(numbers,inputs);
}
