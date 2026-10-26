
Mini-Project 3: Shape Area & Perimeter Calculator

Objective: Develop a calculator that computes the area and perimeter of different shapes through a common interface.

1. Classes and Objects
A class is a user-defined type that bundles data (variables) and the functions that work on that data. 
An object is one real instance built from the class. A class is like the plan of a house; each house built from the plan is an object.
Constructor. A constructor is a special member function with the same name as the class and no return type. It runs automatically when an object is created and sets up its data. In Circle(double r) : radius(r) {}, the part after the colon is the member initializer list: it sets radius directly when the object is created.
In the project.
•	There are four classes: Shape, Circle, Rectangle and Triangle.
•	Every shape the user adds from the menu becomes an object: new Circle(r), new Rectangle(l, w) or new Triangle(a, b, c).
•	Two circles of radius 5 and 2.5 are two separate objects of the same class, each with its own radius.
•	Shape is an abstract class , so you cannot create an object of it; you create objects of its derived classes.

2. Encapsulation
    Encapsulation means binding data and the functions that operate on it together in one class, and hiding the data
   from outside code so it can be used only through the class's own functions. It is also called data hiding.
   
How C++ does it: access specifiers.
Specifier	Who can access the member
private	        Only the class itself
protected	The class and its derived classes
public	        Any code
In a class, members are private by default.

In the project. radius, length, width and the triangle's three sides are all private. Outside code such as main() cannot
write c.radius = -5;. The only ways in are the constructor (which sets the values) and the public functions area(), perimeter(), name() 
and dimensions() (which read them).

3. Inheritance
Inheritance lets a new class (the derived class) acquire the members of an existing class (the base class). It models an "is-a" relationship: a Circle is a Shape.
Term	                Meaning	In the project
Base class (parent)	The class being inherited from	Shape
Derived class (child)	The class that inherits	Circle, Rectangle, Triangle
Public inheritance	Base's public members stay public in the derived class	class Circle : public Shape

4. Function Overriding
Overriding means a derived class provides its own body for a function that the base class already declares. The function must have the same name, same parameters, same return type and same const-ness
Overloading vs overriding.
	     Overloading	                    Overriding
Where	     Within one class	           Between base and derived class
Signature    Must differ in parameters  	Must be the same
Binding      Compile time	            Run time (when the function is virtual)
Needs virtual	No	                   Yes, to get run-time behaviour

5. Virtual Functions
 A virtual function is a member function in a base class that you expect to be overridden in derived classes. Declaring it virtual ensures that the correct function is called for an object, regardless of the type of pointer or reference used for the call. This supports polymorphism by allowing dynamic method resolution: the function call is resolved at run time, not compile time.
Why it is needed. Without virtual, the compiler picks the function from the pointer's type:
Pure virtual functions and abstract classes. A pure virtual function has no body and is declared with = 0. A class with at least one pure virtual function is an abstract class: you cannot create objects of it, and it exists only to be a base class. It defines what derived classes must do, not how.
virtual double area() const = 0;     // pure virtual
Shape s;                             // ERROR: cannot instantiate an abstract class

6. Runtime Polymorphism
 Polymorphism means "many forms": one call behaves differently depending on the object it acts on. Runtime polymorphism (also called dynamic dispatch or late binding) means the function to execute is decided at run time, from the actual type of the object.
Requirement	In the project
Inheritance	Circle, Rectangle, Triangle inherit from Shape
Function overriding	Each derived class overrides area() and perimeter()
Virtual function	area() and perimeter() are virtual in Shape
Base-class pointer or reference   	vector<Shape*> shapes and showShape(const Shape& s, ...)








