#include"calcu.h"
using namespace std;
int main(int argc, char *argv[])
{
	cal c;
	int u, z;
	char *p = argv[1];
	char *p2;
	p2 = argv[2];
	int total;
	total = c.fileread(p);
	c.boundary();
	u = c.test(total, p2);
	z = total - u;
	c.print(u, z);
	system("pause");
	return 0;
}
