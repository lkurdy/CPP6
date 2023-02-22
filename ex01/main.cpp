#include "Serializer.hpp"

int	main()
{
	Data	d;
	Data	*f = NULL;
	uintptr_t	t;

	d.a = 5;
	d.l = 12345678910;
	d.c = '=';
	t = Serializer::serialize(&d);
	f = Serializer::deserialize(t);
	std::cout << f->a << std::endl << f->l << std::endl << f->c << std::endl;
	return (0);
}
