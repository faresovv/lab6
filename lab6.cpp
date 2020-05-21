#include <iostream>
#include <fstream>
using namespace std;
double f(double x, double y)
{
	return x * x - 22 * x + 2 * y * y + 28 * y + 222;
}
double gradX(double x, double y)
{
	return 2 * x - 22;
}
double gradY(double x, double y)
{
	return 4 * y + 28;
}
int main()
{
	ofstream out;
	out.open("ans.dat");
	double L = 1.0;
	double x = 1, y = 1;
	int i = 0;
	out << x << " " << y << endl;
	while (L > 0.1)
	{
		i++;
		if (f(x - L * gradX(x, y), y - L * gradY(x, y)) <= (f(x, y) - 0.5 * L * (gradX(x, y) * gradX(x, y) + gradY(x, y) * gradY(x, y))))
		{
			x = x - L * gradX(x, y);
			y = y - L * gradY(x, y);
		}
		else
		{
			L = L * 0.5;
		}
		out << x << " " << y << endl;
	}
	cout << "x=" << x << "   " << "y=" << y << endl;
	cout << "f(x,y)=" << f(x, y) << endl;
	cout << "itera=" << i << endl;
	return 0;
}