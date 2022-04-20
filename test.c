#include <stdio.h>

static char	*ft_subst(char *str, char c1, char c2)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (str[i])
	{
		if (str[i] == c1 && p == 0)
		{
			str[i] = c2;
			p = 1;
		}
		else
			p = 0;
		i++;
	}
	return (str);
}

int	main()
{
	char str[] = "%dklasdnasjk%cvvdv%%dcjnscjds%i%%";
	printf("%s", ft_subst(str, '%', 'O'));

	return (0);
}
