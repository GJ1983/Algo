#include<iostream>

/* 
 * 1. Even the exception is caught by reference, it is not possible for catch block, to modify the local object at throw site, it can only modify a copy
 * 2, When an object is copied for used in exception, the copy is being performed by object's copy constructor. This copy contructor is one in the class corresponding to object's static type not it's dynamic type.
 */


/* 
 * catch(Widget& w)
 *{
 *  throw;
 *}
 *
 *
 *catch(Widget& w)
 *{
 *  throw w;
 *}
 *
 * The difference between above 2 is , first one throws the current exception, while the second one throw the copy of the current exception.
 * First block is more efficient in terms of performace, Also one other important thing is first block throws the current exception regradless of it's type, However the second block will throws the copy of current exception whic will always be of the type of Widget.
 */


class Widget
{
};

class SpecialWidget : public Widget
{
};

void passandThrowObjects()
{
	SpecialWidget sw;
	Widget &wd = sw;   // wd pointing to SpecialWidget

	throw wd ;  // This throws an object of Widget , Although it is pointing to SpecialWidget, Reason mentioned in point 2 above
}

int main()
{
	return 0;
}
