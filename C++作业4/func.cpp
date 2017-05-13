#include"calcu.h"
void cal::writefile(char *str, char *p)
{
	FILE *out;
	if ((out = fopen(p, "a")) == NULL)
	{
		cout << "Can not write it!!!";
		exit(0);
	}
	fputs(str, out);
	fputs("\n", out);
}

void cal::print(int v, int c)
{
	char temp0[20] = { 0 }, temp1[20] = { 0 };
	cout << "Right:" << v << endl;
	cout << "Wrong:" << c << endl;
	temp0[0] = 'R';
	temp0[1] = 'i';
	temp0[2] = 'g';
	temp0[3] = 'h';
	temp0[4] = 't';
	temp0[5] = ':';
	temp0[6] = v + 48;

	writefile(temp0, p);

	temp1[0] = 'W';
	temp1[1] = 'r';
	temp1[2] = 'o';
	temp1[3] = 'n';
	temp1[4] = 'g';
	temp1[5] = ':';
	temp1[6] = c + 48;
	writefile(temp1, p);


}

void cal:: boundary()
{
	srand(time(NULL));
	int pq;
	cout << "0(����) 1(Enlish):";
	cin >> pq;
	cout << "*******************************************************" << endl;
	if (pq == 0)
		cout << "�Ѷ�д�ɹ�";
	if (pq == 1)
		cout << "Already done(Use # to end this test.)";
	cout << endl << "*******************************************************" << endl;
}

void cal::random(int *a, int*b, int*c, int *d)
{
	*a = 10 * rand() / RAND_MAX;
	*b = 10 * rand() / RAND_MAX;
	*c = 10 * rand() / RAND_MAX;
	*d = 10 * rand() / RAND_MAX;
	while (*b == 0 || *d == 0)
	{
		*b = 10 * rand() / RAND_MAX;
		*d = 10 * rand() / RAND_MAX;
	}
}
int cal::fileread(char *p1)
{
	pr = p1;
	FILE *in;
	char c[50] = { 0 };
	char ch[2]{ 0 };
	if ((in = fopen(pr, "r")) == NULL)
	{
		cout << "Can not open it!!!";
		exit(0);
	}
	fgets(ch, 2, in);
	return ch[0] - '0';
}
char cal::randop()
{
	char sign;
	int int_sign;
	srand(time(NULL));
	int_sign = 4;
	switch (int_sign)
	{
	case 1:sign = '+'; break;
	case 2:sign = '-'; break;
	case 3:sign = '*'; break;
	case 4:sign = '/'; break;
	}
	return sign;
}
string cal::int_string(int number)
{
	int temp = abs(number);
	char str[200];
	_itoa_s(temp, str, 10,10);
	return str;
}

float cal::calcusum(int a, int b, char sig)
{
	float v, a1, b1;
	a1 = a;
	b1 = b;
	switch (sig) 
	{
	case '+':v = a1 + b1; break;
	case '-':v = a1 - b1; break;
	case '*':v = a1*b1; break;
	case '/':v = a1 / b1; break;
	}
	return v;
}

string cal::combine(string a, string b, char sign)
{
	string st;
	st = a + sign + b;
	return st;
}

int cal::generateExpression(int x)
{
	string str, str_num1, str_num2, str_num3, str_num4,temp1,temp2,temp;
	string t;
	char sign1, sign2, signm;
	int w = 0;
	float sum1,sum2,sum, reply;
	int x1, x2, y1, y2;
	x = x % 2;
	random(&x1, &y1, &x2, &y2);
	sign1 = randop();
	sign2 = randop();
	signm = randop();
	str_num1 = '('+int_string(x1);
	str_num2 = int_string(y1)+')';
	str_num3 = '('+int_string(x2);
	str_num4 = int_string(y2)+')';
	if (x == 0)
	{
		sum1 = calcusum(x1, y1, sign1);
		sum1 = (int)(sum1 * 100 + 0.5) / 100.0;
		temp1 = combine(str_num1, str_num2, sign1);
		temp1 = temp1 + "=?";
		cout << temp1 << endl;
		writefile(&temp1[0], p);
		cin >> reply;
		ostringstream ss1;
		ss1 << reply;
		string str1 = ss1.str();
		writefile(&str1[0], p);
		cout << "Right answer:" << sum1 << endl;
		ostringstream ss2;
		ss2 << sum1;
		string str2 = ss2.str();
		str2 = "Right answer:" + str2;
		writefile(&str2[0], p);
		if (reply == sum1)
			return 1;
		else
			return 0;
	}
	else
	{
		sum1 = calcusum(x1, y1, sign1);
		temp1 = combine(str_num1, str_num2, sign1);
		sum2 = calcusum(x2, y2, sign2);
		temp2 = combine(str_num3, str_num4, sign2);
		temp = combine(temp1, temp2, signm)+"=?";
		sum = calcusum(sum1, sum2, signm);
		sum = (int)(sum * 100 + 0.5) / 100.0;
		cout << temp << endl;
		writefile(&temp[0], p);
		cin >> reply;
		ostringstream ss3;
		ss3 << reply;
		string str3 = ss3.str();
		writefile(&str3[0], p);

		cout << "Right answer:" << sum << endl;
		ostringstream ss4;
		ss4 << sum1;
		string str4 = ss4.str();
		str4 = "Right answer:" + str4;
		writefile(&str4[0], p);
		if (reply == sum)
			return 1;
		else
			return 0;
	}

	

	
}
int cal::test(int total, char *p1)
{
	int i, v, u = 0;
	p = p1;
	for (i = 0; i<total; i++)
	{
		v = 8 * rand() / RAND_MAX;
		u = u + generateExpression(v);
		if (getchar() == '#')
		{
			u++;
			break;
		}
	}
	return u;
}

