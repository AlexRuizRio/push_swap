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

int verificiar (int argc, char *argv[])
{
    int i;
    int y;

    i = 1;
    while(i < argc)
    {
        y = i;

        while(++y < argc)
        {
            if ( ft_strncmp(argv[i], argv[y], 11) == 0)
            {
                return (write(1, "Error\n", 6));
            }
        }
        i++;
    }
    return (0);
}
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