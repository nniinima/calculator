#ifndef __FT_EVALEXPR_H
# define __FT_EVALEXPR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

char		*g_str;
char		*ft_eliminate();
char		ft_current();
char		ft_next();
double		ft_op_secondary();
double		ft_number();
double		ft_verify();
double		ft_op_primary();
double		ft_eval_expr();
#endif
