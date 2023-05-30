#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

bool	isNumber(std::string value)
{
	char	c;
	double	d;
	std::stringstream s(value);

	if (s >> d)
	{
		return (s.eof() || (s >> c && c == 'f' && value.find('.') != std::string::npos));
	}
	else
		return (false);
}

void	ScalarConverter::convert(std::string value)
{
	if (value.size() == 1 && !isdigit(value[0]))
	{
		if (value[0] <= 31 || value[0] == 127)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: " << value << std::endl;
		std::cout << "int: "<< static_cast<int>(value[0]) << std::endl; 
		std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
	}
	else if (isNumber(value) || !value.compare("-inff") || !value.compare("+inff") || !value.compare("nanf") || !value.compare("-inf") || !value.compare("+inf") || !value.compare("nan"))
	{
		double	d = atof(value.c_str());
		int	i = static_cast<int>(d);
		float	f = static_cast<float>(d);
		char	c = static_cast<char>(d);
		std::ostringstream	o;

		o << d;
		std::string s = o.str();
		if (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity() || isnan(d) || d > INT_MAX || d < INT_MIN)
		{
			std::cout << "char: Impossible\n";
			std::cout << "int: Impossible\n";
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
		else
		{	
			if (d > 127 || d < 0)
				std::cout << "char: Impossible\n";
			else if (c <= 31 || c == 127)
				std::cout << "char: Non displayable\n";
			else
				std::cout << "char: " << c << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << f;
			if ((isdigit(s[0]) || s[0] == '-') && s.find('.') == std::string::npos)
				std::cout << ".0";
			std::cout << "f" << std::endl;
			std::cout << "double: " << d;
			if ((isdigit(s[0]) || s[0] == '-' ) && s.find('.') == std::string::npos)
				std::cout << ".0";
			std::cout << std::endl;
		}
	}
	else
		std::cout << "Type conversion not possible\n";
}
