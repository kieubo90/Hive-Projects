# include <unistd.h>
#include <stdlib.h>
#  define LENGTH 9

int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	is_valid_line(char *str)
{
	if (ft_strlen(str) != 9)
		return (0);
	while (*str)
	{
		if (!((*str >= '1' && *str <= '9') || (*str == '.')))
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_input(int argc, char **argv)
{
	int index;

	if (argc != 10)
		return (0);
	index = 1;
	while (index < 10)
	{
		if (!is_valid_line(argv[index]))
			return (0);
		index++;
	}
	return (1);
}

int	check_empty(char **sudoku, int *row, int *column)
{
	*row = 0;
	while (*row < LENGTH)
	{
		*column = 0;
		while (*column < LENGTH)
		{
			if (sudoku[*row][*column] == '0')
				return (1);
			*column += 1;
		}
		*row += 1;
	}
	return (0);
}

int	check_in_row(char **sudoku, int row, char number)
{
	int column;

	column = 0;
	while (column < LENGTH)
	{
		if (sudoku[row][column] == number)
			return (1);
		column++;
	}
	return (0);
}

int	check_in_column(char **sudoku, int column, char number)
{
	int row;

	row = 0;
	while (row < LENGTH)
	{
		if (sudoku[row][column] == number)
			return (1);
		row++;
	}
	return (0);
}

int	check_in_box(char **sudoku, int row, int column, char number)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (sudoku[i + row][j + column] == number)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_legal(char **sudoku, int row, int column, char number)
{
	if (!check_in_row(sudoku, row, number) &&
		!check_in_column(sudoku, column, number) &&
		!check_in_box(sudoku, row - (row % 3), column - (column % 3), number))
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**print_array(char **argv)
{
	char	**sudoku;
	int		i;
	int		j;

	sudoku = malloc(sizeof(char *) * LENGTH);
	i = 0;
	while (i < LENGTH)
	{
		sudoku[i] = malloc(sizeof(char));
		i++;
	}
	i = 0;
	while (i < LENGTH)
	{
		j = 0;
		while (j < LENGTH)
		{
			sudoku[i][j] = (argv[i + 1][j] == '.') ? '0' : argv[i + 1][j];
			j++;
		}
		i++;
	}
	return (sudoku);
}

void	create_sudoku(char **sudoku)
{
	int i;
	int j;

	i = 0;
	while (i < LENGTH)
	{
		j = 0;
		while (j < LENGTH)
		{
			ft_putchar(sudoku[i][j]);
			if (j != LENGTH - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	solve_it(char **sudoku)
{
	int row;
	int column;
	int number;

	if (!check_empty(sudoku, &row, &column))
		return (1);
	number = 1;
	while (number <= 9)
	{
		if (check_if_legal(sudoku, row, column, number + '0'))
		{
			sudoku[row][column] = number + '0';
			if (solve_it(sudoku))
				return (1);
			sudoku[row][column] = '0';
		}
		
		number++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**sudoku;

	if (!(is_valid_input(argc, argv)))
	{
		write(1, "Error\n", 7);
		return (0);
	}
	sudoku = print_array(argv);
	if (solve_it(sudoku))
	{
		create_sudoku(sudoku);
		return (1);
	}
	write(1, "Error\n", 7);
	return (0);
}