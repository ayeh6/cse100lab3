//	numbers[inputs].at(digit)
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int digits;

int findBig(vector<int> numbers[],int inputs,int digits) {
	int big = -1;
	for(int i=0; i<inputs; i++)
	{
		if(big < numbers[i].at(digits));
		{
			big = numbers[i].at(digits);
		}
	}
}

void print(vector<int> numbers[],int inputs) {
	for(int i=0; i<inputs; i++)
	{
	        for(int j=0; j<10; j++)
	        {
	                cout << numbers[i].at(j) << ";";
		}
		if (inputs != inputs-1)
		{
			cout << endl;
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
	//int biggest = findBig(numbers,inputs,digits);
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
	int v = 0;
	int w = 0;
	for (int k=0;k<biggest;k++)
	{
		v = 0;
		while(C[k] > 0 && w < inputs)
		{
			if(numbers[v].at(digits) == k)
			{
				copyVector(numbers,sorted,v,w,inputs);
				w++;
				C[k]--;
			}
			if(C[k] == 0)
			{
				break;
			}
			v++;
			if(v == inputs)
			{
				v = 0;
			}
		}
	}
	digits--;
	if (digits < 0)
	{
		print(sorted,inputs);
	}
	else
	{
		MyFunc(sorted,inputs,digits);
	}
}


int main(int argc,char **argv) {
	int inputs;
	digits = 9;
	cin >> inputs;
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
	MyFunc(numbers,inputs,digits);
}
