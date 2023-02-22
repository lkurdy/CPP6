#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <string>
# include <sstream>
# include <stdlib.h>
# include <limits>
# include <limits.h>
# include <math.h>

class   ScalarConverter
{
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();

		static void	convert(std::string value);
};

#endif
