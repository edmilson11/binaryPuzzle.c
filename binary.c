
#include<stdio.h>
#include<stdbool.h>
/*Testa norte, sul, leste, oeste; tem o valor que pode ser zero ou um. Se tiver, retorna true e altera o valor*/
int testa_norte(int i, int j, int v)
{
    int m[i][j];
    for (i=0; i<6; i++)
    {
        /*Avalia se nao sai da matriz para o norte*/
        if(i>0)
        return(m[i][j]&&m[i-1][j]==v);
        else
            return false;
    }
}
int testa_sul(int i, int j, int v)
{
    int m[i][j];
    for (i=0; i<6; i++)
    {
        /*Avalia se nao sai da matriz para o sul*/
        if(i>0)
        return(m[i][j]&&m[i+1][j]==v);
        else
            return false;
    }
}
int testa_oeste(int i, int j, int v)
{
    int m[i][j];
    for (j=0; j<6; j++)
    {
        /*Avalia se nao sai da matriz para o oeste*/
        if(j>0)
        return(m[i][j]&&m[i][j-1]==v);
        else
            return false;
    }
}
int testa_leste(int i, int j, int v)
{
    int m[i][j];
    for (j=0; j<6; j++)
    {
        /*Avalia se nao sai da matriz para o leste*/
        if(j>0)
        return(m[i][j]&&m[i][j+1]==v);
        else
            return false;
    }
}
int testa_norte_alt(int i, int j, int v)
{
    int m[i][j];
    for (i=0; i<6; i++)
    {
        if(i>1)
        return(m[i][j]&&m[i-2][j]==v);
        else
            return false;
    }
}
int testa_sul_alt(int i, int j, int v)
{
    int m[i][j];
    for (i=0; i<6; i++)
    {
        if(i>1)
        return(m[i][j]&&m[i+2][j]==v);
        else
            return false;
    }
}
int testa_oeste_alt(int i, int j, int v)
{
    int m[i][j];
    for (j=0; j<6; j++)
    {
        if(j>1)
        return(m[i][j]&&m[i][j-2]==v);
        else
            return false;
    }
}
int testa_leste_alt(int i, int j, int v)
{
    int m[i][j];
    for (j=0; j<6; j++)
    {
        if(j>1)
        return(m[i][j]&&m[i][j+2]==v);
        else
            return false;
    }
}
/*funcao que altera valor se valor for igual a i ou j lido*/
int altera(int i, int j, int v){
    int m[i][j];
    for(i=0; i<6; i++)
        for(j=0; j<6; j++){
            m[i][j] = !m[i][j];
        }
}
int avaliaSeg(int i, int j, int v)
{
    /*Avalia se tem zeros seguido se sim  altera valor*/
    if (testa_norte(i, j, v))
        altera(i-2, j,!v);
    if (testa_sul(i,j,v))
        altera(i+2,j,!v);
    if (testa_leste(i,j,v))
        altera(i,j+2,!v);
    if (testa_oeste(i,j,v))
        altera(i,j-2,!v);
}
int avaliaAlt(int i, int j, int v)
{
    /*avalia se tem zeros e uns alternados*/
    if (testa_norte_alt(i,j,v))
        altera(i-1, j, !v);
    if (testa_sul_alt(i,j,v))
        altera(i+1,j, !v);
    if (testa_leste_alt(i,j,v))
        altera(i,j+1, !v);
    if (testa_oeste_alt(i,j,v))
        altera(i, j-1, !v);
}
int bpuzzle(int i, int j)
{
    bool FLAG;
    int m[i][j];
    for(i=0; i<6; i++)
        for (j=0; j<6; j++)
        {
            /*Se valaor igual a 2, ainda nao foi preenchido*/
            if (m[i][j] ==2) FLAG = true;
            if (m[i][j] ==0)
            {
                /*Avalia se tem zero seguido de zero*/
                avaliaSeg(i, j, 0);
                /*Avalia se tem zero alternados*/
                avaliaAlt(i,j, 0);
            }
            if (m[i][j]==1){
                /*Avalia se tem 1 seguido de 1*/
                avaliaSeg(i, j, 1);
                /*Avalia se tem 1 alternados*/
                avaliaAlt(i, j, 1);
            }
        }
    
}

int main()
{
    int m[6][6];
    int i, j;
    /*FLAG verifica se ja esta tudo preenchido se sim, retorna false e sai*/
    bool FLAG =true;
    while(FLAG)
    {
        FLAG = false;
        for (i=0; i<6; i++)
            for (j=0; j<6; j++)
            {
                /*isere a matriz*/
                scanf("%d", (*(m+i)+j) );
            }
        /*Ler a matriz ja resolvida*/
        for (i=0; i<6; i++)
        {
        for(j=0; j<6; j++)
            {
                /*esperado imprimer a matriz resolvida*/
                *(*(m+i)+j)=bpuzzle(i ,j);
            }
        
        for (i=0; i<6; i++)
        {
        for(j=0; j<6; j++)
            {
                /*esperado imprimer a matriz resolvida*/
                printf("%d ", *(*(m+i)+j));
            }
            printf("\n");
        }
        return 0;
        
        }
    }

    
}