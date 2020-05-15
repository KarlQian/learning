
 #include "file.h"
 void testMessage() 
{
	Message m0;
	Message m1("hello");
	Message m2("world");
	Folder f1("f1");
	Folder f2("f2");
	m1.save(f1);
	m2.save(f2);
	Message m4 = m2;
	
	swap(m1, m4);

}