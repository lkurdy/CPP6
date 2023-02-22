#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base	*generate()
{
	time_t	t;
	time(&t);
	srand(t);
	int	random = rand() % 3 + 1;
	Base	*b = NULL;

	if (random == 1)
		b = new A;
	else if (random == 2)
		b = new B;
	else
		b = new C;
	return (b);
}

void	identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "I'm an A class\n";
	B *b = dynamic_cast<B*>(p);
	if (b)
		std::cout << "I'm an B class\n";
	C *c = dynamic_cast<C*>(p);
	if (c)
		std::cout << "I'm an C class\n";
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "I'm a ref to A class\n";
	}
	catch (std::exception &e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "I'm a ref to B class\n";
		}
		catch (std::exception &e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "I'm a ref to C class\n";
			}
			catch (std::exception &e)
			{
				std::cout << "unexpected error\n";
			}
		}
	}
}

int	main()
{
	Base	*base = generate();
	Base	&ref = *base;

	identify(base);
	identify(ref);
	delete base;
	return (0);
}
