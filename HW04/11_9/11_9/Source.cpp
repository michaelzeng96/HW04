#include <iostream>
using namespace std;

class Rectangle2D
{
private:
	double dX;
	double dY; 
	double dWidth;
	double dHeight;
public:
	Rectangle2D();
	Rectangle2D(double setX, double setY, double setWidth, double setHeight);
	double getX(void) const;
	double getY(void) const;
	double getWidth(void) const;
	void setWidth(double setWidth);
	double getHeight(void) const;
	void setHeight(double setHeight);
	double getArea(void) const;
	double getPerimeter(void) const;
	bool contains(double x, double y) const;
	bool contains(const Rectangle2D &r) const;
	bool overlaps(const Rectangle2D &r) const;
};

Rectangle2D::Rectangle2D()
{
	dX = 0;
	dY = 0;
	dWidth = 1;
	dHeight = 1;
}

Rectangle2D::Rectangle2D(double setX, double setY, double setWidth, double setHeight)
{
	dX = setX;
	dY = setY;
	dWidth = setWidth;
	dHeight = setHeight;
}

double Rectangle2D::getX(void) const
{
	return dX;
}

double Rectangle2D::getY(void) const
{
	return dY;
}

double Rectangle2D::getWidth(void) const
{
	return dWidth;
}

void Rectangle2D::setWidth(double setWidth) 
{
	dWidth = setWidth;
}

double Rectangle2D::getHeight(void) const
{
	return dHeight;
}

void Rectangle2D::setHeight(double setHeight)
{
	dHeight = setHeight;
}

double Rectangle2D::getArea(void) const
{
	return dWidth*dHeight;
}

double Rectangle2D::getPerimeter(void) const
{
	return (dWidth + dHeight) * 2;
}

bool Rectangle2D::contains(double x, double y) const
{
	double xMax = dX + (dWidth / 2);
	double xMin = dX - (dWidth / 2);
	double yMax = dY + (dHeight / 2);
	double yMin = dY - (dHeight / 2);

	if ((x <= xMax && x >= xMin) && (y <= yMax &&y >= yMin))
	{
			return true;
	}

	return false;
}

bool Rectangle2D::contains(const Rectangle2D &r) const
{
	double xMax = dX + (dWidth / 2);
	double xMin = dX - (dWidth / 2);
	double yMax = dY + (dHeight / 2);
	double yMin = dY - (dHeight / 2);

	double obj_xMax = r.dX + (r.dWidth / 2);
	double obj_xMin = r.dX - (r.dWidth / 2);
	double obj_yMax = r.dY + (r.dHeight / 2);
	double obj_yMin = r.dY - (r.dHeight / 2);

	if (obj_xMax <= xMax && obj_xMin >= xMin && obj_yMax <= yMax && obj_yMin >= yMin)
	{
		return true;
	}

	return false;
}

bool Rectangle2D::overlaps(const Rectangle2D &r) const
{
	double xMax = dX + (dWidth / 2);
	double xMin = dX - (dWidth / 2);
	double yMax = dY + (dHeight / 2);
	double yMin = dY - (dHeight / 2);

	double obj_xMax = r.dX + (r.dWidth / 2);
	double obj_xMin = r.dX - (r.dWidth / 2);
	double obj_yMax = r.dY + (r.dHeight / 2);
	double obj_yMin = r.dY - (r.dHeight / 2);

	if (obj_xMax <= xMax || obj_xMin >= xMin || obj_yMax <= yMax || obj_yMin >= yMin)
	{
		return true;
	}

	return false;
}



int main()
{
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);

	cout << "r1's area is " << r1.getArea() << endl;
	cout << r1.contains(3, 3) << endl;
	cout << r1.contains(r2) << endl;
	cout << r1.overlaps(r3) << endl;
	
	return 0;
}