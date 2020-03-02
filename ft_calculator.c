/**
 * @Author: Niko Niinimaki <ukkoodin>
 * @Date:   2020-03-02T18:38:53+02:00
 * @Email:  niko.niinimaki@gmail.com
 * @Last modified by:   ukkoodin
 * @Last modified time: 2020-03-02T18:53:58+02:00
 */

#include "ft_evalexpr.h"

double		ft_verify(void)
{
	double 	result;

	if (ft_current() >= '0' && ft_current() <= '9')
		return (ft_number());
	else if (ft_current() == '(')
	{
		ft_next();
		result = ft_op_secondary();
		ft_next();
		return (result);
	}
	else if (ft_current() == '-')
	{
		ft_next();
		return (-ft_verify());
	}
	return (0);
}

double		ft_op_primary(void)
{
	double	result;
	char	operand;

	result = ft_verify();
	while (ft_current() == '*' || ft_current() == '/' || ft_current() == '%')
	{
		operand = ft_next();
		if (operand == '*')
			result = result * ft_verify();
		else if (operand == '/')
			result = result / ft_verify();
		else
			result = fmod(result, ft_verify());
	}
	return (result);
}

double		ft_op_secondary(void)
{
	double result;

	result = ft_op_primary();
	while (ft_current() == '+' || ft_current() == '-')
		if (ft_next() == '+')
			result = result + ft_op_primary();
		else
			result = result - ft_op_primary();
	return (result);
}

double		ft_number(void)
{
	double result;

	result = ft_next() - '0';
	while (ft_current() >= '0' && ft_current() <= '9')
	{
		result = 10 * result + ft_next() - '0';
	}
	return (result);
}
