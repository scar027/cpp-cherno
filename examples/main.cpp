#include <iostream>
#include <string>
#include "sample-library/Log.h"
#include "sample-library/Multiply.h"
#include "sample-library/InitLog.h"
#include "sample-library/MultiplyandLog.h"
#include "sample-library/Increment.h"
// header files get copied into the main file
// C standard library header files will have a .h extension while C++ standard 
// library header files wont.
// While using #include "" is used while writing relative paths
// void Log(const char* message); //declaration

class Player
{
	// by default a class makes all its variables private
	// this means that only functions inside the class can access it
	// public allows you to access variables from outside the class
	public:
		int x, y;
		int speed;

	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}	

};

void Move2(Player& player, int xa, int ya)
{
	player.x += xa * player.speed;
	player.y += ya * player.speed;
}

struct Vec2 
{
	float x, y;

	void Add(const Vec2& other)
	{
		x += other.x;
		y += other.y;
	}
};

class Logr{
	public:
		const int LogLevelError = 0;
		const int LogLevelWarning = 1;
		const int LogLevelInfo = 2;

		// public:
		// enum Level
		// {
		// 	LoglevelError, LogLevelWarning, LogLevelInfo
		// };

	private:
		int m_LogLevel = LogLevelInfo;
		// m_ represents that its a class member variable only.
		//Level m_LogLevel = LogLevelInfo;

	public:
		void SetLevel(int level)
		{
			m_LogLevel = level;
		}

		void Error(const char* message)
		{
			if (m_LogLevel >= LogLevelError)
				std::cout << "[ERROR]: " << message << std::endl;
		}

		void Warn(const char* message)
		{
			if (m_LogLevel >= LogLevelWarning)
				std::cout << "[WARNING]: " << message << std::endl;
		}

		void Info(const char* message)
		{
			if (m_LogLevel >= LogLevelInfo)
				std::cout << "[INFO]: " << message << std::endl;
		}

		
};

static int s_var =  10; // static variable declaration

struct Entity 
{
	int x, y;

	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

struct EntityStatic
{
	static int x, y;

	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

int EntityStatic::x;
int EntityStatic::y;

enum Example
{
		E, F, G // notice that this line doesnt end with a semicolon.
		// vales assigned by default start from 0 and progress for every new enum
};

enum Example8bit: unsigned char
{	
		P, Q, R // specifying the data type to limit number of bits used
};

class EntityNew
{
	public: 
		float X, Y;

		// the constructor is a special type of method that gets created everytime you create
		// a class object

		//EntityNew() = delete; deletes the default constructor 

		EntityNew()
		{
			X = 0.0f;
			Y = 0.0f;
			std::cout << "Created Entity!" << std::endl;
		}

		// overloaded constructor
		EntityNew(float x, float y)
		{
			X = x;
			Y = y;
		}	

		~EntityNew()
		{
			std::cout << "Destroyed Entity!" << std::endl;
		}

		void Init()
		{
			// function to manually initialize the class objects
			X = 0.1f;
			Y = 0.1f;
		}

		void Print()
		{
			std::cout << X << ", " << Y << std::endl;
		}
};

void Function()
{	
	// sample function to test the destruction of the EntityNew class object
	EntityNew e;
	e.Print();
}

class EntityAgain
{
	public:
		float X,Y;
  
  void Move(float xa, float ya)
  {
    X += xa;
    Y += ya;
  }
};

class PlayerAgain : public EntityAgain
{
  public:
    const char* Name;

    void PrintName()
    {
      std::cout << Name << std::endl;
    }
};

class EntityOnceAgain
{
  public:
    std::string GetName() { return "Entity";}
};

class PlayerOnceAgain : public EntityOnceAgain
{
  private:
    std::string m_Name;

  public:
    PlayerOnceAgain(const std::string& name) : m_Name(name) {}
    std::string GetName() { return m_Name; }
}; 

void PrintName(EntityOnceAgain* entity)
{
  std::cout << entity->GetName() << std::endl;
}

class EntityVirtual
{
	public:
    virtual std::string GetName() { return "Entity";}

};

class PlayerVirtual : public EntityVirtual
{
  private:
    std::string m_Name;

  public:
    PlayerVirtual(const std::string& name) : m_Name(name) {}
    std::string GetName() override { return m_Name; }
};


class Printable
{
	public:
	// pure virtual function
		virtual std::string GetClassName() = 0;
};

class EntityPrintable : public Printable
{
	public:
		virtual std::string GetName() { return "Entity";}
		std::string GetClassName() override {return "Entity";}
};

class PlayerPrintable : public EntityPrintable
{
	private:
    std::string m_Name;

  public:
    PlayerPrintable(const std::string& name) : m_Name(name) {}
		std::string GetName() override { return m_Name; }
    std::string GetClassName() override { return "Player"; }
};

void Print(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

void PrintString(const std::string& string)
{
	std::cout << string << std::endl;
}

class EntityConst
{
	private:
		int m_X, m_Y;
	
	public:
		int GetX() const // const after function works only for classes
		{	
			// m_X = 2 would generate an error
			return m_X;
		}

		void SetX(int x)
		{
			m_X = x;
		}

};

class EntityMutable
{
	private:
		std::string m_Name;
		mutable int m_DebugCount = 0;

	public:
		const std::string& GetName() const 
		{ 
			m_DebugCount++;
			return m_Name; 
		}	
};

class EntityInitializer
{
	private:
		std::string m_Name;
		int m_Score;

	public:
		EntityInitializer()
			: m_Name("Unknown"), m_Score(0)
			// Initializations must be made in the order in which they are written in private
			{

			}
		// {
		// 	m_Name = "Unknown";
		// }

		EntityInitializer(const std::string& name)
		{
			m_Name = name;
		}

		const std::string& GetName() const { return m_Name; }
};

static int s_Level = 12;
static int s_Speed = 2;


int main() {
	Log("\n---------------------[ Working ]---------------------------\n");
	Log("Hello World!");
	std::cout << "Hello World!" << std::endl;
	
	Log("\n---------------------[ Compiler ]---------------------------\n");
	int res1 = Multiply(6,7);
	std::cout << res1 << std::endl;
	
	Log("\n---------------------[ Linker ]---------------------------\n");
	// the linker pulls in all the object files generated during compilation
	// and libraries and stitch them into a single files
	// writing the keyword static before a function declaration tells the 
	// linker that the function will be used only in this translation unit
	// two or more identically named functions with the same return type will cause a 
	// linking error(duplicate symbols)
	InitLog();
	
	Log("\n---------------------[ Variables ]---------------------------\n");
	char c1 = 'A'; //1 byte
	c1 = 20;
	short s1 = 'A'; // 2 bytes
	int var1 = 8; // 4 bytes
	var1 = 20;
	long l1 = 1; // 4 bytes
	long long ll1 = 2; // 8 bytes
	// use unsigned keyword to get rid of signed bit

	float f1 = 5.5f; // 4 bytes
	double d1 = 6.67; // 8 bytes
	bool b1 = true;

	// print data types to console
	std::cout << c1 << std::endl;
	std::cout << s1 << std::endl;
	std::cout << b1 << std::endl;
	std::cout << "Size of long long data type is: " << sizeof(long long) << std::endl;
	
	Log("\n---------------------[ Functions ]---------------------------\n");
	MultiplyandLog(7,2);
	
	Log("\n---------------------[ Header Files ]---------------------------\n");
	// #pragma once prevents us from including a single header file multiple times into 
	// a single translation unit
	// classical way to write header files without using #pragma once:
	// ifndef _LOG_H
	// #define _LOG_H
	// ..............
	// #endif

	Log("\n---------------------[ Debugging ]---------------------------\n");
	int a = 8;
	a++;
	const char* string = "Hello";

	for (int i = 0; i < 5; i++) {
		const char c = string[i];
		std::cout << c << std::endl;
	}

	Log("The loop has finished execution");

	Log("\n---------------------[ Conditions & Branching ]---------------------------\n");
	int x = 5;
	bool comparisonResult = x == 5;
	if (comparisonResult)
	{
		Log("The comparison result is True!");
	}else if (x == 7)
	{
		Log("x is equal to 7");
	}
	
	const char* ptr = nullptr;
	if (ptr)
	{
		std::cout << ptr << std::endl;
	}else if (ptr == "Hello") 
	{
		Log("Pointer is Hello");
	}else
	{
		Log("Ptr is null!");
	}
		
	// Prefer using mathematical operations over conditional statements to increase speed

	Log("\n---------------------[ Loops ]---------------------------\n");	

	for (int i = 0; i < 5; i++) Log("This statement will print 5 times!");

	Log("\n");

	int i = 0;
	while (i < 5)
	{
		Log("This statement will also print 5 times!");
		i++;
	}
	
	Log("\n");
	i = 0;
	do
	{
		Log("This statement is printed eventhough i = 0");
	} while (i < 0);

	Log("\n---------------------[ Control Flow ]---------------------------\n");
	Log("Note how the for loop skips every even iteration in the for loop below: ");
	for (int i = 0; i < 5; i++) 
	{
		if (i % 2 == 0) continue;
		std::cout << i << std::endl;
	}
	Log("\n");

	Log("Note how the for loop ends after the third iteration: ");
	for (int i = 0; i < 5; i++) 
	{
		if (i  == 3) break;
		std::cout << i << std::endl;
	}
	
	Log("\n---------------------[ Pointers ]---------------------------\n");
	// The single most important thing in programming would be memory
	// A pointer is an integer which stores a memory address
	// 0 is not a valid memory address
	// NULL is basically #define NULL 0
	int var = 8;
	int* ptr1 = &var; // & helps get the memory address of a variable which can be stored
	// the type of the pointer becomes important only when dereferencing is involved
	std::cout << "The variable declared is located at: " << ptr1 << std::endl;
	*ptr1 = 10; // Dereferencing the pointer and modifying the value stored in it.
	std::cout << "The new value modified after dereferencing is: " << var << std::endl;

	// allocating 8 bytes of memory and returning a pointer to the start of the 
	// memory address to those 8 bytes of memory
	char* buffer = new char[8];
	//memset(buffer, 0, 8); 
	// memset(<ptr>, <value to be filled in memory>, <no.of bytes to be filled with that value)

	Log("\n---------------------[ References ]---------------------------\n");
	// Pointers in disguise(syntax-sugar)
	// References themselves don't occupy memory they are just a reference to a variable
	a = 5;
	int& ref = a;
	ref = 2;
	std::cout << "The variable 'a' changes to " << ref << " now" << std::endl;

	Increment(&a);
	std::cout << "The variable 'a'increments to " << ref << " now" << std::endl;

	// references cannot be changed once they are declared
	// pointers can be changed on the other hand(as they need to be dereferenced prior to using) 
	// so if requied use them 

	Log("\n---------------------[ Classes ]---------------------------\n");
	// way to group data or functionality
	Player player;
	// variables made from class types are called objects and a new object variable is called an
	// instance
	// Creatinng a function to change arguments of the objects from within the class
	player.x = 1;
	player.y = 1;
	player.speed = 5;

	Move2(player, 1, -1);
	// Implementing the function from outside the class
	std::cout << "The moved coordinates are" << "( " << player.x << ", " << player.y << " )" << std::endl;

	player.x = 1;
	player.y = 1;
	player.speed = 5;

	player.Move(1,-1);
	// Implementing the function from within the class
	std::cout << "The moved coordinates are" << "( " << player.x << ", " << player.y << " )" << std::endl;

	// Anything that can be done with classes can be done without it as well
	// Hence languages such as C exist

	Log("\n---------------------[ Classes vs Structs ]---------------------------\n");
	// basically same as class other than the fact that structs are public by default
	// structs ensure backward compatibility of C++ with C since classes dont exist there
	// good to use when creating a class that just represents plain old data such as variables
	Vec2 vec1;
	vec1.x = 5;
	vec1.y = 6;
	
	Vec2 vec2;
	vec2.x = 5;
	vec2.y = 6;

	vec1.Add(vec2);
	std::cout << "The addition of the vectors is" << "( " << vec1.x << ", " << vec1.y << " )" << std::endl;

	Log("\n---------------------[ Class ]---------------------------\n");
	// Logger with 3 levels: Error, Warning, Info

	Logr logr;
	logr.SetLevel(logr.LogLevelWarning);
	//logr.SetLevel(Logr::LogLevelError);
	logr.Warn("This is a warning!");
	logr.Error("This is an error!");
	logr.Info("This is an Info!");

	Log("\n---------------------[ Static(Outside Class) ]---------------------------\n");
	// static outside a class means linkage of symbol declared as static will be internal
	// i.e it will only be visible to that translation unit
	// static inside a class means the variable will share memory with all instances of the class
	// static variable declared before main()

	std::cout << s_var << std::endl;
	// use extern keyword to refer to variable defined in an external translation unit
	// the above wont work if the external variable is defined as static though

	Log("\n---------------------[ Static(Inside Class) ]---------------------------\n");
	// only 1 variable across all class instances.
	// changing the variable would result in the change being reflected across all classes 
	// employing that variable
	Log("The values of the variables inside the class change as below without staic: ");
	Entity e1;
	e1.x = 2;
	e1.y = 3;

	Entity e2 = {5, 8};

	e1.Print();
	e2.Print();

	EntityStatic es1;
	e1.x = 2;
	e1.y = 3;

	EntityStatic es2;
	es1.x = 5;
	es1.y = 8;

	Log("The final value assigned to variable is used when static keyword is used: ");
	es1.Print();
	es2.Print();

	Log("Hence, we can refer to the variable directly of the class: ");
	EntityStatic::x = 7;
	EntityStatic::y = 12;
	es1.Print();
	es2.Print();

	// static methods cant access non static variables since static methods dont have a 
	// class instance
	// a static method is same as writing a method outside a class and clearly variables
	// limited to the scope of the class wouldnt be defined outside

	Log("\n---------------------[ Enums ]---------------------------\n");
	// way to name values(integers) to improve code readability
	// generally used to name only for specific values defined

	Log("\n---------------------[ Constructors ]---------------------------\n");
	EntityNew en1;
	en1.Init();
	Log("The values initialized by the manually initialized constructor: ");
	std::cout << en1.X << std::endl;
	std::cout << en1.Y << std::endl;

	EntityNew en2;
	Log("The values initialized by the default constructor: ");
	std::cout << en2.X << std::endl;
	std::cout << en2.Y << std::endl;

	EntityNew en3(5.3f, 6.7f);
	Log("The values initialized by the overloaded constructor: ");
	std::cout << en3.X << std::endl;
	std::cout << en3.Y << std::endl;

	Log("\n---------------------[ Destructors ]---------------------------\n");
	Function();
	// memory allocated on the heap needs to be manually cleaned up

	Log("\n---------------------[ Inheritance ]---------------------------\n");
  PlayerAgain playerAgain;
  playerAgain.X = 1;
  playerAgain.Y = 1;
  playerAgain.Move(5, 5);

  Log("The values after moving the player are: ");
	std::cout << playerAgain.X << std::endl;
	std::cout << playerAgain.Y << std::endl;

  Log("\n---------------------[ Virtual Functions ]---------------------------\n");
  EntityOnceAgain* eoa1 = new EntityOnceAgain();
  std::cout << eoa1->GetName() << std::endl;

  PlayerOnceAgain* poa1 = new PlayerOnceAgain("Player01");
  std::cout << poa1->GetName() << std::endl;

  // The above fails when we use the concept of polymorphism
  EntityOnceAgain* eoa2 = poa1;
  std::cout << eoa2->GetName() << std::endl;
  // the above line prints Entity instead of Player01!
  Log("\n");

  PrintName(eoa1);
  PrintName(poa1);

  // now demonstrating virtual functions
  Log("\n");

  EntityVirtual* ev1 = new EntityVirtual();
  std::cout << ev1->GetName() << std::endl;

  PlayerVirtual* pv1 = new PlayerVirtual("Player01");
  std::cout << pv1->GetName() << std::endl;

  Log("\n---------------------[ Interfaces ]---------------------------\n");
  // force subclasses to implement methods that are only declared(unimplemented) 
  // in the base class

	EntityPrintable* ep1 = new EntityPrintable();
	PlayerPrintable* pp1 = new PlayerPrintable("Player01");

	Print(ep1);
	Print(pp1);

	Log("\n---------------------[ Visibility ]---------------------------\n");
	// only meant to help you organize code doesnt affect code performance
	// private: can only be accessed in the defined class
	// protected: can be accessed by subclasses as well
	// public: can be accessed from outside the class as well

	Log("\n---------------------[ Arrays ]---------------------------\n");
	// used to represent a collection of data
	// an array is really just a pointer
	int ex[5];
	int* ptrex = ex;

	ex[0] = 1;
	ex[4] = 1;

	int ex0 = ex[0]; // created on the stack, destroyed when end of main() and get out of the scope.
	std::cout << "The 1st element of the Array is:" << ex0 << std::endl;

	for (int i = 0; i < 5; i++) ex[i] = 2;
	std::cout << "The modified array is: [" << ex[0] << ", " << ex[1] << ", " << ex[2] << ", " << ex[3] << ", " << ex[4] << "] " << std::endl;

	ex[2] = 5;
	std::cout << "The modified array is: [" << ex[0] << ", " << ex[1] << ", " << ex[2] << ", " << ex[3] << ", " << ex[4] << "] " << std::endl;

	*(ptrex + 2) = 6;
	std::cout << "The modified array is: [" << ex[0] << ", " << ex[1] << ", " << ex[2] << ", " << ex[3] << ", " << ex[4] << "] " << std::endl;

	// if you wanted to actually deal with the bytes when using the pointer you could 
	// cast the pointer to char first(only 1 byte long)
	*(int*)((char*)ptrex + 8) = 7;
	std::cout << "The modified array is: [" << ex[0] << ", " << ex[1] << ", " << ex[2] << ", " << ex[3] << ", " << ex[4] << "] " << std::endl;

	int* aex = new int[5]; // created on heap(allocated dynamically), stays alive until destroyed
	// used when returning a brand new array created inside a function
	for (int i = 0; i < 5; i++) aex[i] = 2;
	delete aex;

	// size of array ex
	int count = sizeof(ex)/ sizeof(int);
	// sizeof returns number of bytes taken by the array, hence
	std::cout << "The size of the array 'ex' is: " << count << std::endl;
	// we must divide by the bytes taken by the data type stored by the array
	// can only be used with stack allocated arrays else sizeof returns size of 
	// pointer not array

	Log("\n---------------------[ Strings ]---------------------------\n");
	// group of characters(letters, numbers, symbols ...)
	// strings as const char pointers
	const char* name = "Cherno";
	char name2[7] = {'C', 'h', 'e', 'r', 'n', 'o', 0};
	// char name2[7] = {'C', 'h', 'e', 'r', 'n', 'o', /0};
	std::cout << name << std::endl;
	std::cout << name2 << std::endl;
	// const because we want strings to be immutable
	// 0 is null termination character to represent end of string
	std::string name3 = "Cherno";
	std::cout << "The size of the string is: " << name3.size() << std::endl;

	std::string name4 = "Cherno ";
	name4 += "Hello!"; // adding pointer to string and += overloads string class to allow it
	std::string name5 = std::string("Cherno ") + "Hello!";
	std::cout << name4 << std::endl;
	std::cout << name5 << std::endl;

	// finding text in a string
	bool contains = name4.find("no") != std::string::npos;
	std::cout << "Does the string contain 'no' ?: " << contains << std::endl;

	std::cout << "The string contains 'no' at: " << name4.find("no") << std::endl;

	PrintString(name4);

	Log("\n---------------------[ String Literals ]---------------------------\n");
	// string literals always stored in ROM
	const char* name6 = u8"Cherno"; // 1 byte/char
	const wchar_t* name7 = L"Cherno"; // 2 bytes/char
	const char16_t* name8 = u"Cherno"; // 2 bytes/char
	const char32_t* name9 = U"Cherno";	// 4 bytes/char

	//using namespace std::string_literals;
	// std::u32string name10 = U"Cherno"s + U" Hello!";
	
	const char* example = R"(This is 
	a
	multiline
	string)";

	const char* example2 = "This is\n"
	"a\n"
	"multiline\n"
	"string";

	std::cout << example << std::endl;
	Log("\n");
	std::cout << example2 << std::endl;

	Log("\n---------------------[ Const ]---------------------------\n");
	// promise but can be bypassed
	const int MAX_AGE = 90;
	int* ptr2 = new int;
	*ptr2 = 2;
	ptr2 = (int*)&MAX_AGE;
	std::cout << *ptr2 << std::endl;

	// int const* is the same as const int* (const before *)
	int* const ptr3 = new int; // to make ptr const, const should be after *

	Log("\n---------------------[ Mutable ]---------------------------\n");
	// mutable as lambdas

	int newVar = 8;
	auto f = [=]() mutable
	{	
		newVar++;
		std::cout << newVar << std::endl;
	};

	f();
	std::cout << newVar << std::endl;

	Log("\n---------------------[ Member Initializer Lists ]---------------------------\n");
	// use to initialize class members in a constructor
	EntityInitializer ei1;
	std::cout << ei1.GetName() << std::endl;

	EntityInitializer ei2("Cherno");
	std::cout << ei2.GetName() << std::endl;

	Log("\n---------------------[ Ternary Operators ]---------------------------\n");
	// syntax sugar for if statements
	s_Speed = ( s_Level > 5 ) ? 10 : 5;
	std::cout << s_Speed << std::endl;

	// var = ( condition ) ? (statement to be executed if condn true) : (stat to be exec if condn false)
	std::string rank = s_Level > 10 ? "Master" : "Beginner";

	// Nested ternary operator
	s_Speed = ( s_Level > 5 ) ? ( s_Level > 10 ) ? 15 : 10 : 5;
	std::cout << s_Speed << std::endl;
	
	Log("\n---------------------[ Instansiate Objects ]---------------------------\n");
	// lifetime of stack objects is limited to the scope in which they are declared

	
	std::cin.get();
	return 0;

}
