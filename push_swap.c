
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

long ft_isnumber (const char *str)
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
int store_numbers(char **tmp, long *argi, int *z) {
    int j = 0;

    while (tmp[j]) {
        if (!ft_isnumber(tmp[j])) {
            while (tmp[j])
                free(tmp[j++]);
            free(tmp);
            return (-1);
        }
        argi[(*z)++] = ft_strlong(tmp[j]);
        free(tmp[j++]);
    }
    free(tmp);
    return (0);
}

int sacarstring(int argc, char *argv[], long *argi) {
    int i = 1, z = 0;
    char **tmp;

    while (i < argc) {
        if (contains_space(argv[i])) {
            tmp = ft_split(argv[i], ' ');
            if (tmp == NULL || store_numbers(tmp, argi, &z) == -1)
                return (write(1, "Error\n", 6));
        } else {
            if (!ft_isnumber(argv[i]))
                return (write(1, "Error\n", 6));
            argi[z++] = ft_strlong(argv[i]);
        }
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
// Haay que revisarla ya que no podemos si las dan errores o algo hay que liberar bien
// la memoria y tambien falta cerrar la lista a la cabecera
int main(int argc, char *argv[]) 
{
	t_stack *stacka;
	t_stack *header;
  	int i;
	int count;
	long *argi;

	stacka = NULL;
	count = parseo (argc, argv) + 1;
	//printf ("%d", i);
	argi = malloc(count * sizeof(long));
	if(argi == NULL)
		return(-1);
	if (sacarstring(argc, argv, argi) == 6)
		return (-1);
  	i = checker_arg(count, argi);
  	if(i == 6)
    	return(-1);
	
	header = enter_data(count, argi, &stacka);
	while(stacka->next != NULL)
	{
		printf("%ld ", stacka->nbr);
		stacka = stacka->next;
	}
	printf ("\n%p", header);
free(argi);
  return (i);
}

t_stack *enter_data(int count, long *argvi, t_stack **stacka)
{
	t_stack *node;
	t_stack *former;
	t_stack *header;
	int i;

	i = 0;
	node = ft_stcknew(argvi[i], i);
	if (node == NULL)
		return (NULL);	
	former = node;
	header = node;
	*stacka = header;
	while (++i < count) 
    {
        node = ft_stcknew(argvi[i], i);
        if (node == NULL)
		{
			ft_stckclear(stacka);
			return (NULL);
		}
        ft_stckadd_back(stacka, node, former);
        former = node;
    }
    return (header);
}


