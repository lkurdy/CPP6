#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include <string>
# include "Data.hpp"

typedef unsigned long long uintptr_t;

class   Serializer
{
		Serializer();
	public:
		Serializer(const Serializer &other);
		Serializer	&operator=(const Serializer &other);
		~Serializer();

		static	uintptr_t	serialize(Data *ptr);
		static Data	*deserialize(uintptr_t raw);
};

#endif
