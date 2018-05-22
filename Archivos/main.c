#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;
}eDato;

void funcion1 ();
void funcion2 ();
void funcion3 ();
void funcion4 ();
void funcion5 ();
void funcion6 ();
void funcion7 ();

int main()
{
    //funcion1();
    //funcion2();
    //funcion3();
    //funcion4();
    //funcion5();
    //funcion6();
    funcion7();

    /*FILE* pArchivo;
    char cadena[50];

    pArchivo = fopen("archivo.txt","r");

    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
        fgets(cadena, 50, pArchivo);
        puts(cadena);
        }
    }


    pArchivo=fopen("archivo.txt","w");

    if(pArchivo !=NULL)
    {
        fprintf(pArchivo, "Tengo que aprobar!!");
        fclose(pArchivo);
        printf("\nEl Archivo ha sido Guardado en: C:\\TEST\\archivo.txt.-");
    }

    else
    {
        printf("\nEl Archivo o directorio no existe!!");
    }
    return 0;*/
}

void funcion1 ()
{

    FILE* miArchivo;
    int numero=159;

    miArchivo = fopen("prueba1.txt","w");
    fwrite(&numero,sizeof(int),1,miArchivo);
    fclose(miArchivo);


}

void funcion2 ()
{

     FILE* miArchivo;
    int numero;

    miArchivo = fopen("prueba1.txt","r");
    fread(&numero,sizeof(int),1,miArchivo);
    printf("NUMERO: %d", numero);
    fclose(miArchivo);

}

void funcion3()
{

    int i=0;
    int numero;
    int lista[5];
    FILE* miArchivo;

    miArchivo = fopen("pruebaVec.txt","w");

    for(i=0; i<5; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numero);
        getchar();

        fwrite(&numero,sizeof(int),1,miArchivo);
    }

    fclose(miArchivo);

}

void funcion4()
{

    int lista[5];
    int i=0;
    FILE* miArchivo;
    miArchivo = fopen("pruebaVec.txt","r");


    while(!feof(miArchivo));
    {
        fread(&lista[i],sizeof(int),1,miArchivo);
        i++;
    }

    for(i=0; i<5; i++)
    {

        printf("\n%d", lista[i]);
    }
    fclose(miArchivo);
}

void funcion5()
{

    FILE* miArchivo;
    eDato d = {3,'A'};
    //int numero=128;
    //int otroNumero;

    miArchivo = fopen("numero.dat","wb");
    fwrite(&d, sizeof(eDato), 1, miArchivo);

    fclose(miArchivo);


}

void funcion6 ()
{
    FILE* miArchivo;
    eDato d;

    miArchivo = fopen("numero.dat","r");
    fread(&d, sizeof(eDato),1,miArchivo);

    fclose(miArchivo);

    printf("\n%d %c", d.a, d.b);

}

void funcion7()
{
    FILE* miArchivo;
    eDato d[2]={(3,'A'),(4,'C')};
    eDato d2[2];
    int numero=128;
    int otroNumero;
    int i;

    miArchivo = fopen("numero1.dat","wb");
    fwrite(&d, sizeof(eDato), 2, miArchivo);

    fclose(miArchivo);

    miArchivo = fopen("numero1.dat","rb");
    fread(d2, sizeof(eDato),2,miArchivo);
    fclose(miArchivo);

    for(i=0; i<2; i++)
    {
        printf("\n%d--%c", d2[i].a, d2[i].b);
    }


}
