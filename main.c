#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>

#define LINHAS 3
#define COLUNAS 5

int * iniciar_lista(int array_length);
int **cria_slot(int **slot);

int main()
{
    // BLOCO DE CODIGO DA QUESTAO 1 - Quando for testar descomentar
    /*FILE *in=fopen("arquivo.txt","r");
    struct stat sb;
    stat("arquivo.txt", &sb);
    char *palavras = malloc(sb.st_size);
    while (fscanf(in, "%[^\n] ", palavras) != EOF) {
        printf("maior palindromo %d\n",palindromo(palavras));
    }
    fclose(in);
    */




    // BLOCO DE CODIGO DA QUESTAO 2 - Quando for testar descomentar
    /*char * romano = "MDCDLXXIV";
    printf("O numero %s corresponde ao valor decimal %d\n", romano, numeros_romanos(romano));
    romano = "IV";
    printf("O numero %s corresponde ao valor decimal %d\n", romano, numeros_romanos(romano));
    romano = "VI";
    printf("O numero %s corresponde ao valor decimal %d\n", romano, numeros_romanos(romano));
    romano = "XII";
    printf("O numero %s corresponde ao valor decimal %d\n", romano, numeros_romanos(romano));
    romano = "IX";
    printf("O numero %s corresponde ao valor decimal %d\n", romano, numeros_romanos(romano));
    romano = "VIII";
    printf("O numero %s corresponde ao valor decimal %d\n", romano, numeros_romanos(romano));
    */





    // BLOCO DE CODIGO DA QUESTAO 3 - Quando for testar descomentar
    /*vermelho(3);*/




    // BLOCO DE CODIGO DA QUESTAO 4 - Quando for testar descomentar
    /*int array_length = 8;
    int * lista = {iniciar_lista(array_length)};
    mergeKListas(lista,array_length);
    */



    // BLOCO DE CODIGO DA QUESTAO 5 - Quando for testar descomentar
    /*int premio[LINHAS][COLUNAS] = {{1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}};
    int **slot = 0;
    int lines = 0;
    int cols = 0;
    slot = cria_slot(slot);
    //int comp = slot[0][0];
    int count_prize = 0;
    while (lines < 3 && count_prize != 5)
    {
        while (cols < 5)
        {
            if (slot[0][0] == slot[lines][cols] && premio[lines][cols])
            {
                count_prize++;
            }
            cols++;
        }
        cols = 0;
        lines ++;
        if (lines == 3 && count_prize != 5)
        {
            lines = 0;
            while (lines < 3)
            {
                free (slot[lines++]);
            }
            free(slot);
            lines = 0;
            cols = 0;
            count_prize = 0;
            slot = cria_slot(slot);
            //comp = slot[0][0];
        }
    }
    printf ("Ganhou!\n");
    */


    return 0;
}

//Questao 1
int palindromo(char palavra[])
{
    int tamanho_maior_palindromo = 0;
    int listaIndice[strlen(palavra)];
    int index_inicio;
    int index;
    char letra_a_procurar;
    int index_fim;
    int inicio;
    int fim;
    int meio;
    int contador_tamanho_palindromo;
    int temp;
    bool sequencia;
    for (int i = 0; i < strlen(palavra); i++)
    {
        index_inicio = i;
        index = index_inicio;
        letra_a_procurar = palavra[i];
        for (int j = 0; j < strlen(palavra); j++)
        {
           if (palavra[j] == letra_a_procurar)
           {
               listaIndice[index] = j;
               index++;
           }
        }

        index_fim = index;

        if(index_inicio>index_fim)
        {
            temp = index_inicio;
            index_inicio = index_fim;
            index_fim = temp;
        }

        for(int k = index_inicio; k < index_fim; k++)
        {
            if((k+1)<index_fim)
            {
                inicio = listaIndice[k];
                fim = listaIndice[k+1];


                meio = inicio+((fim - inicio)/2);
                contador_tamanho_palindromo = 0;
                sequencia = true;
                for(int l = inicio,m=fim; l<= meio; l++,m--)
                {

                    if(!sequencia)
                    {
                        contador_tamanho_palindromo = 0;
                    }

                    if((palavra[l]==palavra[m])&&(l!=m)&&sequencia)
                    {
                        contador_tamanho_palindromo+=2;
                    }
                    else if(l==meio){
                        contador_tamanho_palindromo++;
                        break;
                    }
                    else{
                        sequencia = false;
                    }
                }

                if((contador_tamanho_palindromo>1)&& (tamanho_maior_palindromo<contador_tamanho_palindromo))
                {
                    tamanho_maior_palindromo = contador_tamanho_palindromo;
                }
            }
        }
    }
    return tamanho_maior_palindromo;

}

//Questao 2
int numeros_romanos(char numero[])
{
    int total = 0;
    int length = strlen(numero);
    for(int i = 0; i < length; i++)
    {
        int corrente_valor = 0;
        if(numero[i]=='I')
        {
            corrente_valor = 1;
        }

        if(numero[i]=='V')
        {
            corrente_valor = 5;
        }

        if(numero[i]=='X')
        {
            corrente_valor = 10;
        }

        if(numero[i]=='L')
        {
            corrente_valor = 50;
        }

        if(numero[i]=='C')
        {
            corrente_valor = 100;
        }

        if(numero[i]=='D')
        {
            corrente_valor = 500;
        }

        if(numero[i]=='M')
        {
            corrente_valor = 1000;
        }

        if((i+1)<length)
        {
            if(numero[i]=='I' && numero [i+1] == 'V')
            {
                corrente_valor = 4;
                i++;
            }

            if(numero[i]=='I' && numero [i+1] == 'X')
            {
                corrente_valor = 9;
                i++;
            }

            if(numero[i]=='X' && numero [i+1] == 'L')
            {
                corrente_valor = 40;
                i++;
            }

            if(numero[i]=='X' && numero [i+1] == 'C')
            {
                corrente_valor = 90;
                i++;
            }

            if(numero[i]=='C' && numero [i+1] == 'D')
            {
                corrente_valor = 400;
                i++;
            }

            if(numero[i]=='C' && numero [i+1] == 'M')
            {
                corrente_valor = 900;
                i++;
            }

        }
        total += corrente_valor;
    }


    return total;
}

//Questao 3
void vermelho(int numero_passos)
{
    int inicial = 0x00001A;
    int final = 0xFF001A;
    int corrente_cor = 0x0;
    int p = (final - inicial)/numero_passos;
    for(int i = 0; i < numero_passos; i++)
    {
        corrente_cor += p;
        int cor = inicial + corrente_cor;
        printf("%x\n",cor);
    }
}


//Questao 4
void mergeKListas(int * listas, int listasSize)
{
    for(int i = 0; i < listasSize; i++)
    {
        for(int j = i+1 ; j < listasSize; j++)
        {
            if(listas[j]<listas[i])
            {
                int temp = listas[j];
                listas[j] = listas[i];
                listas[i] = temp;
            }
        }
    }

    for(int k = 0; k < listasSize; k++)
    {
        printf("%d\n",listas[k]);
    }

}

//Questao 4
int * iniciar_lista(int array_length)
{

    struct ListaNode {
        struct ListaNode * next;
        int * data;
        int size;
    };

    int data1 [] = {1,3,8};

    int data2 [] = {1,3,6};

    int data3 [] = {8,9};
    struct ListaNode * vazio = (struct ListaNode *) malloc(sizeof(vazio));
    vazio->size = 0;


    struct ListaNode * lista1 = (struct ListaNode *) malloc(sizeof(lista1));
    lista1->data = data1;
    lista1->size = 3;
    lista1->next = vazio;


    struct ListaNode * lista2 = (struct ListaNode *) malloc(sizeof(lista2));
    lista2->data = data2;
    lista2->next = lista1;
    lista2->size = 3;

    struct ListaNode * lista3 = (struct ListaNode *) malloc(sizeof(lista3));
    lista3->data = data3;
    lista3->next = lista2;
    lista3->size = 2;

    int * lista_unificada = calloc(array_length, sizeof(int));

    struct ListaNode * corrente_no = lista3;
    int index = 0;
    for(int a = 0; a < corrente_no->size;a++,index++)
    {
        lista_unificada[index]=corrente_no->data[a];

        if(((a+1)==corrente_no->size))
        {
            struct ListaNode * corrente_no_next = corrente_no->next;
            corrente_no = corrente_no_next;
            a = -1;
        }

    }

    return lista_unificada;
}


//Questao 5
int **cria_slot(int **slot)
{
    int col;
    int line;
    line = 0;
    slot = malloc (sizeof(int *) * 3);
    while (line < 3)
    {
        slot[line++] = malloc (sizeof (int));
    }
    line = 0;
    col = 0;
    while (line < 3)
    {
        printf("Insira os valores da linha %d:\n", (line + 1));
        while (col < 5)
        {
            scanf("%d", &slot[line][col]);
            col++;
        }
        col = 0;
        line++;
    }
    return (slot);
}





