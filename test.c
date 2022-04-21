#include <stdio.h>

static int	ft_nb_arg(char *s)
{
	int		nb;
	char	*convs;
	int		i;

	convs = "cspdiuxX%%";
	nb = 0;
	while (*s)
	{
		i = 0;
		while (convs[i])
		{
			if (*s == '%' && (*(s + 1) == convs[i]))
			{
				nb++;
				s++;
				break ;
			}
			i++;
		}
		s++;
	}
	return (nb);
}

int	main(void)
{
	char	str[] = "%%%dkl%asdnasjk%cvvdv%%dcjnscjds%i%%";

	printf("%d", ft_nb_arg(str));
	return (0);
}
