
/*
COSAS QUE FALTAN:
	-falta hacer  el parseo que tendri que ser lo primero dado que no pueden meter los numeros asi "32   23     3"
	-falta resolver todos los errores del añadir el numero a la lista:
		-parsea todos los numeros de arg a long.
		- y de mas.

*/

# include "push_swap.h"

//Es  como un atoi pero te devuelve un long en  vez de un int  
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

int ft_isnumber (const char *str)
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
    return (-1);
}

static	size_t	ft_numbercount(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

int	parseo (int argc, char *argv[])
{
	int i;
	int y;
	char *ver;
	int count;

	i = 1;
	count = 0;
	while(i < argc)
	{
		ver = argv[i];
		y = 0;
		while(ver[y] != '\0')
		{
			if (ver[y] == ' ')
			{
				count = count + ft_numbercount(ver, ' ') - 1;
				break;
			}
			y++;
		}
		count++;
		i++;
	}
	return (count);
}

int contains_space(const char *str) {
    while (*str) {
        if (*str == ' ') return 1;
        str++;
    }
    return 0;
}
// toca revisar esta funcion ya que al meter parametros como string me detecta que no es numero 
// y me salta error y si bajo el ft_isnumber me da error por tipos ya que recibe un char
int sacarstring(int argc, char *argv[], long *argi) 
{
    int i = 1; 
	int z = 0; 
	int j;
    char **tmp;

    while (i < argc) {
        if (contains_space(argv[i])) 
		{
            tmp = ft_split(argv[i], ' ');
			if (tmp == NULL)
				return (write(1, "Error\n", 6));
            j = 0;
            while (tmp[j]) 
			{
                argi[z++] = ft_strlong(tmp[j]);
                free(tmp[j++]);
            }
            free(tmp);
        } else 
            argi[z++] = ft_strlong(argv[i]);
		if (!ft_isnumber(argi[i])) 
            return (write(1, "Error\n", 6));
        i++;
    }
	return (0);
}
// Verifica que los numeros no se repitan 
int checker_arg (int count, long argi[])
{
    int     i;
    int     y;


    i = 0;
    while(i < count -1)
    {
        if (argi[i] < -2147483648 || argi[i] > 2147483647)
            return (write(1, "Error\n", 6));
        y = i;
        while(++y < count)
        {
            if (argi[i] == argi[y])
                return (write(1, "Error\n", 6));
        }
        i++;
    }
    return (0);
}

int main(int argc, char *argv[]) 
{
	//t_stack *stacka;
  	int i;
	int count;
	long *argi;
	count = parseo (argc, argv) + 1;
	//printf ("%d", i);
	argi = malloc(count * sizeof(long));
	if(argi == NULL)
		return(-1);
	if (sacarstring(argc, argv, argi) == 6)
		return (-1);
	int j = 0;
	while (j < count - 1) {
		printf("%ld ", argi[j]);
		j++;
	}
	printf("\n");
  	i = checker_arg(count, argi);
  	if(i == 6)
    	return(-1);
	/*
	stacka = enter_data(argc, argv);
	while(stacka->next != NULL)
	{
		printf("%ld ", stacka->nbr);
		stacka = stacka->next;
	}
	*/
free(argi);
  return (i);
}
/*
t_stack *enter_data(int argc, char *argv[])
{
    t_stack *stacka;
	t_stack *node;
	int i;

	i = 1;
		node = ft_stcknew(argv[i], i);
		if (node == NULL)
			return (NULL);
		
	while (i < argc)
	{
		node = ft_stcknew(argv[i], i);
		if (node == NULL)
			return (NULL);
		
	}

    return (stacka);
}
t_stack	*ft_stcknew(void *content, int index)
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->nbr = content;
	node->index = index;
	node->next = NULL;

	return (node);
}
*/
