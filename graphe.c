#include<stdio.h>
#include<stdlib.h>

int chargemath(char *nom_fic_graphe)
{
    int sommet = 0;
    int choice;
    int i,j;
    int boucle = 1;
    int choice_prec = 0;
    FILE *fic_graphe = fopen("graphe.txt", "r");
    if(fic_graphe == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    fscanf(fic_graphe, "%d\n", &sommet);
    int mat[sommet][sommet];
    int successeurs[sommet][sommet];
    while(boucle == 1)
    {
        printf("1) cree la matrice adjacente\n2) afficher la matrice adjacente\n3) nombre de chemin d elongueur 2\n4) crée la liste des successeurs\n5) afficher la liste des successeurs\n6) crée un graphe\n7) parcour en profondeur\n8) quitter le programme\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            fclose(fic_graphe);
            FILE *fic_graphe = fopen("graphe.txt", "r");
            fscanf(fic_graphe, "%d", &sommet);
            system("clear");
            for(i = 0;i < sommet;i++)
            {
                for(j = 0;j < sommet;j++)
                {
                    mat[i][j] = 0;
                }
            }
            while(!feof(fic_graphe))
            {
                int a,b = 0;
                fscanf(fic_graphe, "%d %d", &a, &b);
                mat[a][b] = 1;
            }
            choice_prec = 1;
        }
        if(choice == 2)
        {
            system("clear");
            if(choice_prec == 0)
            {
                printf("erreur matrice non crée\n");
                exit(-1);
            }
            for(i = 0;i < sommet;i++)
            {
                for(j = 0;j < sommet;j++)
                {
                    printf("%d ", mat[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }    
        if(choice == 3)
        {
            system("clear");
            if(choice_prec == 0)
            {
                printf("erreur matrice non crée\n");
                exit(-1);
            }
            int nb_chemin;
            for(i = 0;i < sommet;i++)
            {
                for(j = 0;j < sommet;j++)
                {
                    if(i != j && mat[i][j] == 1)
                    {
                        for(int k = 0;k < sommet;k++)
                        {
                            if(k != i && k != j && mat[j][k] == 1)
                            {
                                nb_chemin = nb_chemin +1;
                            }
                        }
                    }
                }
            }
            printf("le nombre de chemin de longueur 2 est : %d\n\n", nb_chemin);
        }
        if(choice == 4)
        {
            system("clear");
            if(choice_prec == 0)
            {
                printf("erreur matrice non crée\n");
                exit(-1);
            }
            for(i = 0;i < sommet;i++)
            {
                for(j = 0;j < sommet;j++)
                {
                    if(mat[i][j] == 1)
                    {
                        successeurs[i][j] = j;
                    }
                }
            }
        }
        if(choice == 5)
        {
            system("clear");
            if(choice_prec == 0)
            {
                printf("erreur matrice non crée\n");
                exit(-1);
            }
            for(i = 0;i < sommet;i++)
            {
                printf("les successeurs de %d sont: ", i);
                for(j = 0;j < sommet;j++)
                {
                    if(successeurs[i][j] == j)
                    {
                        printf("%d ", j);
                    }
                }
                printf("\n\n");
            }
        }
        if(choice == 6)
        {
            int nb_sommet,nb_darc,arc1,arc2;
            system("clear");
            FILE *fic_creation_graphe = fopen("creation_graphe.txt", "w");
            printf("nombre de sommet :");
            scanf("%d", &nb_sommet);
            fprintf(fic_creation_graphe, "%d\n", nb_sommet);
            printf("nombre d'arcs :");
            scanf("%d", &nb_darc);
            for(i = 1; i < nb_darc+1;i++)
            {
                printf("entrer l'arc numéro %d\n", i);
                scanf("%d %d", &arc1, &arc2);
                fprintf(fic_creation_graphe, "%d %d\n", arc1, arc2);
            }
            fclose(fic_creation_graphe);
        }
        if(choice == 7)
        {
            system("clear");
            if(choice_prec == 0)
            {
                printf("erreur matrice non crée\n");
                exit(-1);
            }
            int marque[sommet];
            int parcour[sommet];
            for(i = 0;i < sommet;i++)
            {
                for(j = 0;j < sommet;j++)
                {
                    if(mat[i][j] == 1 && marque[i] == 0)
                    {
                        marque[i] = 1;
                        marque[j] = 1;
                            parcour[0] = i;
                            parcour[1] = j;
                            i = j;
                            j = 0;
                    }
                    if(i == 2)
                        {
                            parcour[2] = 1;
                        }
                }
            }
            for(i = 0;i < sommet;i++)
            {
                printf("%d", parcour[i]);
                if(i == 0||i == 1)
                {
                    printf("=>");
                }
            }
            printf("\n");
        }
        if(choice == 8)
        {
            boucle = 0;
            system("clear");
            exit(-1);
        }
    }
    fclose(fic_graphe);
}

int main(int argc, char **argv)
{
    chargemath(argv[1]);
    return(0);
}