#include <stdio.h>
void permuter(int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
void triRapid(int tab[], int premier, int dernier) {
    int pivot, i, j;
    if(premier < dernier) {
        pivot = premier;
        i = premier;
        j = dernier;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < dernier)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        triRapid(tab, premier, j - 1);
        triRapid(tab, j + 1, dernier);
    }
}
int main() {
    int tab[100], nbr, i;
  
    printf("\n Entrer le nombre total d'elements:  ");
    scanf("%d", &nbr);
    
    printf("\n Entrer les elements du tableau:  ");
    for(i = 0; i < nbr; i++)
        scanf("%d", &tab[i]);
    
    triRapid(tab, 0, nbr - 1);
    
    printf("\n Tableau apres tri: ");
    for(i = 0; i < nbr; i++)  {
        printf(" %4d", tab[i]);
    }
    printf("\n");
    return 0;
}