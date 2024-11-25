/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickshort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:05:32 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/11/25 17:49:45 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"

// Quick sort in C

void swap(long *a, long *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(long array[], int low, int high) 
{
  int pivot = array[high];
  
  int i = (low - 1);


  for (int j = low; j < high; j++) { // cambiar esto
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(long array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}
// Borrar al comprobar
void printArray(long array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%ld  ", array[i]);
  }
  printf("\n");
}


void mainquicksort(long data[], int n) {
  
  printArray(data, n);
  quickSort(data, 0, n - 1);
  printArray(data, n);
}