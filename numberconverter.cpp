#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

 struct RomanNumber
{
public:
	string get()
	{
		return romanNumber;
	}

	void show()
	{
		cout << "Roman Number is " << romanNumber << endl;
	}

	RomanNumber(const string &input)
	{
		romanNumber = input;
	}

	int convert()
	{
		int length = romanNumber.length();
		int previous = 0;
		bool error = false;
		int nIndex = 0;

		sum = 0;

		while( (error == false) && (nIndex < length) )
		{
			switch(romanNumber[nIndex])
			{
			case 'M':
				sum += 1000;
				if(previous < 1000)
				{
					sum -= 2 * previous;
				}
				previous = 1000;
				break;
			case 'D':
				sum += 500;
				if(previous < 500)
				{
					sum -= 2 * previous;
				}
				previous = 500;
				break;
			case 'C':
				sum += 100;
				if(previous < 100)
				{
					sum -= 2 * previous;
				}
				previous = 100;
				break;
			case 'L':
				sum += 50;
				if(previous < 50)
				{
					sum -= 2 * previous;
				}
				previous = 50;
				break;
			case 'X':
				sum += 10;
				if(previous < 10)
				{
					sum -= 2 * previous;
				}
				previous = 10;
				break;
			case 'V':
				sum += 5;
				if(previous < 5)
				{
					sum -= 2 * previous;
				}
				previous = 5;
				break;
			case 'I':
				sum += 1;
				if(previous < 1)
				{
					sum -= 2 * previous;
				}
				previous = 1;
				break;
			default:
				cout << romanNumber[nIndex] << " is not a Roman Numeral!" << endl;
				error = true;
				sum = 0;
			} // switch

			nIndex++;

		} // while 
		return sum;
	}

	int length() 
	{
		return romanNumber.length();
	}

private:
	string romanNumber;
	int sum;		
};

int decimalToRoman(int sayi) 
{ 
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int i=12;     
    while(sayi>0) 
    { 
      int div = sayi/num[i]; 
      sayi = sayi%num[i]; 
      while(div--) 
      { 
        cout<<sym[i]; 
      } 
      i--; 
    } 
} 

int main()
{
	int secim=0;
	int sayi;
	string myInput;
	int value;

	printf("Hangi islemi yapmak istiyorsunuz\n1-Onluk tabandan Roma rakamina\n2-Roma rakamindan onluk tabana\n\nSeciminiz: ");
	scanf("%d",&secim);
	
	switch(secim)
	{
		case 1:
			printf("Onluk tabandaki sayiyi girin: ");
			cin >> sayi;
			printf("Cevrilmis hali: "); 
			decimalToRoman(sayi);
			break;
		case 2:
			printf("Roma rakamini girin: ");
			cin >> myInput;
			RomanNumber myRomanNumber(myInput);
			value = myRomanNumber.convert();
			printf("Cevrilmis hali: %d",value);
			break;
	}
	
	return 0;
	
	// Emrecan Balgun
	// 2017280011
}
