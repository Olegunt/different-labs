#include <cmath>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Point
{
	private:
	  float x;
	  float y;
	public:
	  Point(float x_,float y_): x(x_),y(y_)
	  {}
	  static Point Polar(int,float);
	  void display()const;
};

inline Point Point::Polar(int rad,float A)
{
	return Point(rad*cos(A),rad*sin(A));	
}

void Point::display()const
{
	cout << "Ближайшая точка на окружности (" << setprecision(3) << x << ";" << y << ")\n";
}

int main(int argc,char** argv)
{
	int iks = 1;
	int igr = 1;
    int radius = 5;
	if(argc > 3)
	{
	  iks = atoi(argv[1]);
	  igr = atoi(argv[2]);
	  radius = atoi(argv[3]);
	}
	else
	  cout <<"Введено мало данных\nПо умолчанию: точка (" << iks << ";" << igr << ") и окружность радиусом " << radius << endl;
	
	if(radius <= 0)
	{
	  cout << "Ошибка: окружности не существует\n";
	  exit(1);
	}
	if((iks == 0)&&(igr == 0))
	{
	  cout << "Любая точка на окружности ближайшая\n";
	  exit(2);
	}
	if((fabs(iks) > radius) || (fabs(igr) > radius))
	{
	  cout << "Введена точка вне окружности\n";
	  exit(3);
	}
	
	float angle;
	angle = atan2(igr,iks);

	Point pt = Point::Polar(radius,angle);
	pt.display();
	return 0;
}

