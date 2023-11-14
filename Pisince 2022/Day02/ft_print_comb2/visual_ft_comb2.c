#include <unistd.h>

void	ft_putchar(char a, char b, char c, char d)
{
		while (b <= '8')
		{
			while (c <= '9')
			{	
				d = b + 1;
				while (d <= '9')
				{
					write (1, &a, 1);
					write (1, &b, 1);
					write (1, " ", 1);
					write (1, &c, 1);
					write (1, &d, 1);
					if (a == '9' && b == '8' && c == '9')
						break ;
					write (1, ", ", 2);
					d++;
				}
				c++;
			}
			b++;
			c = a;
		}
}
void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	d = '0';
	while (a <= '9')
	{
		ft_putchar(a,b,c,d);
		a++;
		b = '0';	
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
