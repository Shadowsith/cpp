#include <String.h>
#include <cstring>

String::String()
{
nlength = 1;
nstring = new char[nlength];
nstring[nlength-1] = '\0';
}

String::String(const char *input)
{
nlength = strlen(input)+1 ;
nstring = new char[nlength];
for(int i = 0; i < (nlength - 1); i++)
{
nstring[i] = input[i];
}
nstring[(nlength-1)] = NULL;
}

String::String(const String& S)
{
nlength = S.nlength;
nstring = new char[nlength];
for(int i = 0; i < (nlength - 1); i++)
{
	nstring[i] = S.nstring[i];
}

if(nstring[nlength - 1] != '\0'){nstring[nlength -1] = '\0';}
}

String::~String()
{
delete[] nstring;
}


int String::length()
{
int i = 0;
while(nstring[i] != '\0')
{i++;}
return i;
}

char& String::at(int loc)
{
return nstring[loc - 1];
}

bool String::empty()
{
	if(nstring[0] == NULL && nlength == 1){return true;}
	else {return false;}
}

void String::swap(String &from)
{
short lena = nlength;short lenb = from.nlength;
char *temp1 = new char[lena];
char *temp2 = new char[lenb];

for(int i = 0; i < (lena- 1); i++)
{
	temp1[i] = nstring[i];
}
if(temp1[lena - 1] != '\0'){temp1[lena -1] = '\0';}

for(int j = 0; j < (lenb- 1); j++)
{
	temp2[j] = from.nstring[j];
}
if(temp2[lenb - 1] != '\0'){temp2[lenb -1] = '\0';}

delete[] nstring;delete[]from.nstring;

nstring = new char[lenb];
nlength = lenb;
from.nstring = new char[lena];
from.nlength = lena;

for(int k = 0; k < (lenb - 1); k++)
{
nstring[k] = temp2[k];
}
if(nstring[lenb -1] != '\0'){nstring[lenb - 1] = '\0';}

for(int l = 0; l < (lena - 1); l++)
{
from.nstring[l] = temp1[l];
}
if(from.nstring[lena -1] != '\0'){from.nstring[lena-1] = '\0';}

delete[]temp1; delete[]temp2;
}


String String::substr(int index, int length)
{
short size = length+1;
char* temp = new char[size];
int j = 0;
for(int i = index, j = 0; i < length; i++, j++)
{
temp[j] = nstring[i];
}
if(temp[size -1 ] != '\0'){temp[size -1] = '\0';}


String RET;
RET.nlength = size;
delete[]RET.nstring;
RET.nstring = new char[size];
for(short m = 0; m < (size - 1);m++)
{
	RET.nstring[m] = temp[m];
}

if(RET.nstring[size-1] != '\0'){RET.nstring[size-1] = '\0';}
return RET;
delete[]temp;
}



bool operator == (const String & S1, const String & S2)
{
	if(S1.nlength == S2.nlength)
	{
		short counter1 = S1.nlength;
		int counter2 = 0;
		int i = 0;
		while(i != counter1)
		{
			if(S1.nstring[i] != S2.nstring[i]){counter2++;}
			i++;
		}
		cout << i << " " << counter2 << endl;
		if(counter2 != 0) {return false;}
		else{return true;}
	}
	else {return false;}

}

ostream& operator <<(ostream & OS, const String& S)
{
OS << S.nstring;
return OS;
}

istream& operator >>(istream & IS,String& S)
{
char* input = new char[100];
IS.getline(input,100);

int i = 0;
while(input[i] != '\0')
{i++;}
S.nlength = i+1;
delete[]S.nstring;
S.nstring = new char[(i+1)];
for(int j = 0; j < (i) ; j++)
{
	S.nstring[j] = input[j];
}
S.nstring[i] = '\0';
delete[]input;
return IS;
}

String& String::operator =(const String &S)
{
nlength = S.nlength;
delete[] nstring;
nstring = new char[nlength];
for(int i = 0 ; i < (nlength -1);i++)
{
nstring[i] = S.nstring[i];
}
nstring[(nlength -1)] = '\0';
return *this;
}

String operator + (const String& S1, const String & S2)
{
int size = S1.nlength + S2.nlength +1;
char * temp = new char[size];
for(int i = 0; i < (S1.nlength -1);i++)
{
temp[i] = S1.nstring[i];
}

int j = 0;
for(short k = S1.nlength , j=0; k < (size-1) ; k++, j++)
{
temp[k] = S2.nstring[j];
}
if(temp[size -1 ] != '\0'){temp[size -1] = '\0';}

String S3;
S3.nlength = size;
delete[] S3.nstring;
S3.nstring = new char [size];
for(int z = 0; z < (size -1); z++)
{
S3.nstring[z] = temp[z];
}
if(S3.nstring[size-1] != '\0'){S3.nstring = '\0';}
return S3;
delete[] temp;
}

