#include <stdio.h>
#include <string.h>

void tabuleiro(int arr[], int arroi[])
{
    printf("\n\t\t\t ___________");
    printf("\n\t\t\t| TABULEIRO |\n __________________________________________________________________");
    printf("\n|[JOGADOR B]\t\t\t\t\t\t\t   |\n|");
    for (int j = 0; j < 7; j++)
    {
        printf(" %d \t", arroi[j]);
    }
    printf("\t   |\n|\t");
    for (int j = 0; j < 7; j++)
    {
        printf(" %d \t", arr[j]);
    }
    printf("   |\n|Posicao:(1)\t(2)\t(3)\t(4)\t(5)\t(6)\t[JOGADOR A]|\n|__________________________________________________________________|\n\n");
}
void fimdejogo(int array[], int arr[])
{
    printf("\n\t\t\tFIM DE JOGO!!!\n");
    for (int i = 0; i < 6; i++)
    {
        array[6] = array[6] + array[i];
        array[i] = 0;
    }
    for (int j = 6; j > 0; j--)
    {
        arr[0] = arr[0] + arr[j];
        arr[j] = 0;
    }
    tabuleiro(array, arr);

}
void inicioA(int arr[])
{
    for (int i = 0; i < 7; i++)
    {
        arr[i] = 4;
    }
    arr[6] = 0;
}
void inicioB(int arr[])
{
    for (int i = 1; i < 8; i++)
    {
        arr[i] = 4;
    }
    arr[0] = 0;
}
int erromaisA(int posicao, int arr[])
{
    while ((arr[posicao - 1] == 0) || (posicao < 1) || (posicao > 6))
    {
        printf("\nJogada invalida. Por favor insira uma nova posicao: ");
        scanf("%d", &posicao);
    }
    return posicao;
}
int erromaisB(int posicao, int arr[])
{
    while ((arr[posicao] == 0) || (posicao < 1) || (posicao > 6))
    {
        printf("\nJogada invalida. Por favor insira uma nova posicao: ");
        scanf("%d", &posicao);
    }
    return posicao;
}
int testedetabuleiroA(int arr[])
{
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] != 0)
        {
            return 1;
        }
        else if ((i == 5) && (arr[i]) == 0)
        {
            return 0;
        }
    }
}
int testedetabuleiroB(int arr[])
{
    for (int i = 6; i > 0; i--)
    {
        if (arr[i] != 0)
        {
            return 1;
        }
        else if ((i == 1) && (arr[i]) == 0)
        {
            return 0;
        }
    }
}
int jogadaA(int arr[], int oponente[], int posicao)
{
    posicao = erromaisA(posicao, arr);
    int mao = arr[posicao - 1];
    int sementes = mao;
    arr[posicao - 1] = 0;

    while (mao != 0)
    {
        for (int i = 0; i < sementes; i++)
        {
            if (posicao + i > 6)
            {
                for (int j = 6; j > 0; j--)
                {
                    if ((mao != 0) && (j > 1))
                    {
                        oponente[j]++;
                        mao--;
                        i++;
                    }
                    else if ((mao != 0) && (j == 1))
                    {
                        oponente[1]++;
                        posicao = 0;
                        i = -1;
                        j--;
                        mao--;
                    }
                    else
                    {
                        j = 0;
                        i = sementes;
                        mao = 0;
                    }
                }
            }
            else
            {
                if ((posicao + i == 6) && (mao == 1))
                {
                    arr[6] = arr[6] + 1;
                    int x = testedetabuleiroA(arr);
                    int y = testedetabuleiroB(oponente);
                    if ((x != 0) && (y != 0))
                    {
                        tabuleiro(arr, oponente);
                        printf("Jogador A pode jogar novamente: ");
                        scanf("%d", &posicao);
                        posicao = erromaisA(posicao, arr);
                        mao = arr[posicao - 1];
                        sementes = mao;
                        i = -1;
                        arr[posicao - 1] = 0;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    if ((mao == 1) && (arr[posicao + i] == 0) && (posicao + i != 7) && (oponente[posicao + i + 1] != 0))
                    {
                        int c = oponente[posicao + i + 1] + 1;
                        arr[6] = arr[6] + c;
                        mao--;
                        oponente[posicao + i + 1] = 0;
                        i = sementes;
                    }
                    else if (mao != 0)
                    {
                        arr[posicao + i]++;
                        mao--;
                    }
                    else
                    {
                        i = sementes;
                    }
                }
            }
        }
    }
}
int jogadaB(int arr[], int oponente[], int posicao)
{
    int mao = arr[posicao];
    int sementes = mao;
    posicao = erromaisB(posicao, arr);
    mao = arr[posicao];
    sementes = mao;
    arr[posicao] = 0;

    while (mao != 0)
    {
        for (int i = 1; i <= sementes; i++)
        {
            if (posicao - i < 0)
            {
                for (int j = 0; j < 6; j++)
                {
                    if ((mao != 0) && (j < 5))
                    {
                        oponente[j]++;
                        mao--;
                        i++;
                    }
                    else if ((mao != 0) && (j == 5))
                    {
                        if (mao != 1)
                        {
                            oponente[5]++;
                            posicao = 6;
                            i = -1;
                            j++;
                            mao--;
                        }
                        else
                        {
                            oponente[5]++;
                            mao--;
                        }
                    }
                    else
                    {
                        j = 6;
                        i = sementes;
                        mao = 0;
                    }
                }
            }
            else
            {
                if ((posicao - i == 0) && (mao == 1))
                {
                    arr[0] = arr[0] + 1;
                    int x = testedetabuleiroB(arr);
                    int y = testedetabuleiroA(oponente);
                    if ((x != 0) && (y != 0))
                    {
                        tabuleiro(oponente, arr);
                        printf("Jogador B pode jogar novamente: ");
                        scanf("%d", &posicao);
                        mao = arr[posicao];
                        sementes = mao;
                        posicao = erromaisB(posicao, arr);
                        mao = arr[posicao];
                        sementes = mao;
                        i = 0;
                        arr[posicao] = 0;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    if ((mao == 1) && (arr[posicao - i] == 0) && (posicao - i != 0) && (oponente[posicao - i - 1] != 0))
                    {
                        int c = oponente[posicao - i - 1] + 1;
                        arr[0] = arr[0] + c;
                        mao--;
                        oponente[posicao - i - 1] = 0;
                        i = sementes;
                    }
                    else if (mao == 0)
                    {
                        i = sementes;
                    }
                    else
                    {
                        arr[posicao - i]++;
                        mao--;
                    }
                }
            }
        }
    }
}
int jogo(int array[], int arroia[])
{
    int y = 1;
    while (y != 0)
    {
        int x;
        if (y != 0)
        {
            printf("\nJogador A escolha a posicao que pretende jogar: ");
            scanf("%d", &x);
            int g = jogadaA(array, arroia, x);
            tabuleiro(array, arroia);
            int v = testedetabuleiroA(array);
            if ((v == 0) || (g == 0))
            {
                y = 0;
                return 0;
            }
            else
            {
                v = testedetabuleiroB(arroia);
                if (v == 0)
                {
                    y = 0;
                    return 0;
                }
            }
            //printf("compilou com sucesso\n");
        }
        if (y != 0)
        {
            printf("\nJogador B escolha a posicao que pretende jogar: ");
            scanf("%d", &x);
            int g = jogadaB(arroia, array, x);
            tabuleiro(array, arroia);
            int v = testedetabuleiroB(arroia);
            if ((v == 0) || (g == 0))
            {
                y = 0;
                return 0;
            }
            else
            {
                v = testedetabuleiroA(array);
                if (v == 0)
                {
                    y = 0;
                    return 0;
                }
            }
            //printf("compilou com sucesso\n");
        }
    }
}

void main()
{
    int array[7];
    int arroia[7];
    inicioA(array);
    inicioB(arroia);
    tabuleiro(array, arroia);
    int c = jogo(array, arroia);
    if (c == 0)
    {
        fimdejogo(array, arroia);
        printf("\n\n\t\t\tObrigado por Jogar!");
    }
    exit(0);
}
