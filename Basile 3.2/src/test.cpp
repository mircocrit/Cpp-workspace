#include "mypoint.h"
#include "mycircle.h"
#include "mytriangle.h"
#include <iostream>

using namespace std;

int main() {

  MyPoint v1(0,0);
  cout << v1.toString() << endl;
  MyPoint v2(3,3);
  cout << v2.toString() << endl;
  MyPoint v3(6,0);
  cout << v3.toString() << endl;

  cout << "Distance v1,v2 " << to_string(v1.distance(v2)) << endl;
  cout << "Distance v2,v3 " << to_string(v2.distance(v3)) << endl;
  cout << "Distance v3,v1 " << to_string(v3.distance(v1)) << endl;
  MyCircle c(v2,3);
  cout << c.toString() << ", area=" << c.getArea() << ", circumference=" << c.getCircumference() << endl;

  MyTriangle t(v1,v2,v3);
  cout << t.toString() << " type " << t.getType() << ", parimeter=" << t.getPerimeter() << ", area="+to_string(t.getArea()) << endl;
  system("pause");
  return 0;
}
