
/*
COSAS QUE FALTAN:
	-falta hacer  el parseo que tendri que ser lo primero dado que no pueden meter los numeros asi "32   23     3"
	-falta resolver todos los errores del añadir el numero a la lista:
		-parsea todos los numeros de arg a long.
		- y de mas.

*/

# include "push_swap.h"

// Esta funcion se encuentra en la libft tambien
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;
	size_t			len;

	len = count * size;
	str = malloc(len);
	i = 0;
	if (str == 0)
		return (0);
	while (len--)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(char));
	len = 0;
	if (str == 0)
		return (0);
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	length = ft_strlen(s);
	if (start >= length)
		return (ft_strdup(""));
	if (length < len + start)
		len = length - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
//Aqui empieza el split
static	size_t	ft_wordcount(char const *s, char c)
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

static	void	ft_freelst(char **lst, int i)
{
	while (i >= 0)
		free(lst[i--]);
	free (lst);
}

static	char	**ft_wordsplit(char **lst, char const *s, char c, int i)
{
	size_t	wlen;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				wlen = ft_strlen(s);
			else
				wlen = ft_strchr(s, c) - s;
			lst[i] = ft_substr(s, 0, wlen);
			if (lst[i] == NULL)
			{
				ft_freelst(lst, i - 1);
				return (NULL);
			}
			s += wlen;
			i++;
		}
	}
	lst[i] = NULL;
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;

	i = 0;
	lst = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (NULL);
	lst = ft_wordsplit(lst, s, c, i);
	if (!lst)
		return (NULL);
	else
		return (lst);
}
//aqui termina el split

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
void sacarstring(int argc, char *argv[], long *argi) {
    int i;
    int y; 
	int z;
	char **tmp;

	i = 1;
	z = 0;
    while (i < argc) {
        char *temp = argv[i];
		y = 0;
        while(temp[y] != '\0')
		{
			if (temp[y++] == ' ')
			{
				tmp = ft_split(temp, ' ');
				y = 0;
				while(tmp[y] != NULL)
				{
					argi[z++] = ft_strlong(tmp[y]);
					free(tmp[y]);
					y++;
				}
				free(tmp);
				break;
			}
		}
        argi[z++] = ft_strlong(temp);
        i++;
    }
}
// Verifica que los numeros no se repitan 
int checker_arg (int argc, char *argv[])
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
	//t_stack *stacka;
  	int i;
	long *argi;
	i = parseo (argc, argv) + 1;
	//printf ("%d", i);
	argi = malloc(i * sizeof(long));
	if(argi == NULL)
		return(-1);
	sacarstring(argc, argv, argi);
		int j = 0;
	while (j < i - 1) {
		printf("%ld ", argi[j]);
		j++;
	}
	printf("\n");
		
  	i = checker_arg(argc, argv);
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