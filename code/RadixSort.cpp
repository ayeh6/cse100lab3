//	numbers[inputs].at(digit)
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int digits;

void print(vector<int> numbers[],int inputs) {
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

void copyVector(vector<int>numbers[], vector<int> sorted[],int V, int W, int inputs) {
	int p;
	for(int i = 0; i < 10; i++)
	{
		p = numbers[V].at(i);
		sorted[W].push_back(p);
	}
}

void MyFunc (vector<int> numbers[], int inputs,int digits) {
	vector<int> sorted[inputs];
		int biggest = 10;
		int C[biggest];
		for (int i=0; i<biggest; i++)
		{
			C[i] = 0;
		}
		for (int j =0; j<inputs; j++)
		{
			C[numbers[j].at(digits)]++;
		}
		for (int j = 0; j<biggest; j++)
		{
			cout << "there are " << C[j] << " " << j << "s" << endl;
		}
		cout << endl;
		int w = 0;
		int v = 0;
		for (int k=0;k<biggest;k++)
		{
//			cout << "looking for " << k << " in vectors" << endl;
			//int v = 0;
			//int w = 0;
			while(C[k] > 0)
			{
				cout << "digit is " << digits << endl;
				if(numbers[v].at(digits) == k)
				{
					cout << "adding to sorted" << endl;
//					cout << "v is " << v << endl << "w is " << w << endl;
					copyVector(numbers,sorted,v,w,inputs);
					w++;
					C[k]--;
				}
				v++;
				if(v == inputs)
				{
//					cout << "looping/reset V" << endl;
					v = 0;
				}
			}
			cout << endl;
		}
		if(digits == 0)
		{
			cout << "printing" << endl;
			print(sorted,inputs);
		}
		else if (digits > 0)
		{
			digits--;
			MyFunc(sorted,inputs,digits);
		}

	//change to sorted vector
//	cout << "gonna go print" << endl;
}


int main(int argc,char **argv) {

	int inputs;
	digits = 9;
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
	MyFunc(numbers,inputs,digits);
}
