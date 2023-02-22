#include "Serializer.hpp"

Serializer::Serializer()
{
	return ;
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
	return ;
}

Serializer	&Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{
	return ;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	t;

	t = reinterpret_cast<uintptr_t>(ptr);
	return (t);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*d = reinterpret_cast<Data*>(raw);
	return (d);
}
