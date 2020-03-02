#include "ft_evalexpr.h"

char	*ft_eliminate(void)
{
	int		i;
	char	*s;
	int		j;

	i = 0;
	j = 0;
	s = (char *)malloc(sizeof(char) * (strlen(g_str) + 1));
	while (g_str[i])
	{
		if (g_str[i] != ' ')
		{
			s[j] = g_str[i];
			j++;
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	ft_current(void)
{
	return (*g_str);
}

char	ft_next(void)
{
	return (*g_str++);
}

double		ft_eval_expr(char *str)
{
	g_str = str;
	g_str = ft_eliminate();
	return (ft_op_secondary());
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("%f", ft_eval_expr(av[1]));
		printf("\n");
	}
	return (0);
}
