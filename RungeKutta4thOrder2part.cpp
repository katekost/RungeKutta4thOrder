#include "cmath"
#include "fstream"
using namespace std;

int main()
{
	double x, y, z, a, b, h, N, k0, l0, k1, l1, k2, l2, k3, l3;
	ofstream f, s;

	f.open("RungeKutta.txt");
	s.open("KuttaRunge.txt");

	z = 1; // y`=z(0)=1
	y = 0; // y(0)=0
	a = 0;
	b = 10;
	N = 1000;
	h = (b - a) / N;
	x = a;
	f << a;
	f << " ";
	f << y;
	f << "\n";
	s << a;
	s << " ";
	s << z;
	s << "\n";

	for (int i = 0; i < N; i++)
	{
		a = a + h;
		k0 = h*z;
		l0 = h*(10 * cos((0 * x)) - 2 * z - 100 * y + 50);
		k1 = h*(z + 0.5*l0);
		l1 = h*(10 * cos(0 * (x + 0.5*h)) - 2 * (z + 0.5*l0) - 100 * (y + 0.5*k0) + 50);
		k2 = h*(z + 0.5*l1);
		l2 = h*(10 * cos(0 * (x + 0.5*h)) - 2 * (z + 0.5*l1) - 100 * (y + 0.5*k1) + 50);
		k3 = h*(z + 0.5*l2);
		l3 = h*(10 * cos(0 * (x + 0.5*h)) - 2 * (z + 0.5*l2) - 100 * (y + 0.5*k2) + 50);
		y = y + (k0 + 2 * k1 + 2 * k2 + k3) / 6;
		z = z + (l0 + 2 * l1 + 2 * l2 + l3) / 6;
		x = x + h;
		f << a;
		f << " ";
		f << y;
		f << "\n";
		s << a;
		s << " ";
		s << z;
		s << "\n";
	}
	f.close();
	s.close();
