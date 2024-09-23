#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_stack
{
    long            nbr;
    long            index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

long	ft_strlong(const char *str)
{
	long	result;
	int	sig;

	result = 0;
	sig = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		else
			sig = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sig);
}

// Esta de aqui lo suyo seria utilizar la libft ya que se encuentra en ella.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i] && n - 1 > i)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int isnumber (const char *str)
{
    while(*str == ' '|| (*str >= '\t' && *str <= '\r'))
        str++;
    if(*str == '-' || *str == '+')
        str++;
    while(*str)
    {
        //printf("%s ", str);
        if(!ft_isdigit(*str))
            return(0);
        str++;
    }
    return (1);
}

// Verifica que los numeros no se repitan 
int verificiar (int argc, char *argv[])
{
    int     i;
    int     y;
    long    num;

    i = 1;
    while(i < argc)
    {
        num = isnumber(argv[i]);
        if(num == 0)
            return(write(1, "Error\n", 6));
        num = ft_strlong(argv[i]);
        if (num < -2147483648 || num > 2147483647)
            return (write(1, "Error\n", 6));
        y = i;
        while(++y < argc)
        {
            if ( ft_strncmp(argv[i], argv[y], 11) == 0)
                return (write(1, "Error\n", 6));
        }
        i++;
    }
    return (0);
}

// A FALTA DE MAS PRUEBAS FALTA HACER EL PARSEO POR SI UN PARAMETRO ME VIENE ASI "4343 45   545 "
int main(int argc, char *argv[]) 
{
  int i = verificiar(argc, argv);
  return (i);
}

/*
int main2() {
    // Crear nodos de la lista
    t_stack *node1 = (t_stack *)malloc(sizeof(t_stack));
    t_stack *node2 = (t_stack *)malloc(sizeof(t_stack));

    // Inicializar nodos
    node1->nbr = 10;
    node1->index = 1;
    node1->next = node2;
    node1->prev = NULL;

    node2->nbr = 20;
    node2->index = 2;
    node2->next = NULL;
    node2->prev = node1;

    // Acceder a los datos
    printf("Node 1: nbr = %ld, index = %ld\n", node1->nbr, node1->index);
    printf("Node 2: nbr = %ld, index = %ld\n", node2->nbr, node2->index);

    // Liberar memoria
    free(node1);
    free(node2);

    return 0;
}
*/