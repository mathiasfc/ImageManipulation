// **********************************************************************
// PUCRS/FACIN
// Programa de testes para manipulação de Imagens
//
// Marcio Sarroglia Pinho
//
// pinho@pucrs.br
// **********************************************************************

#include <iostream>
#include <cmath>

using namespace std;

#ifdef _MSC_VER

#endif

#ifdef WIN32
#include <windows.h>
#include "gl\glut.h"
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#endif

#include "SOIL/SOIL.h"

#include "ImageClass.h"

ImageClass Image, NewImage, ImageAux;

bool bPreenche = false;
bool bPintaPreto = false;

int LIMIAR = 120;

//verde
int LimiarDentinaMin = 80;
int LimiarDentinaMax = 100;
//vermelho
const int LimiarCanal = 40;
//azul
const int LimiarPinos = 160;

#define LARGURA_JAN 1000
#define ALTURA_JAN 500
// **********************************************************************
//  void ConvertBlackAndWhite()
// **********************************************************************
void ConvertBlackAndWhite(int type)
{
    unsigned char r,g,b;
    int x,y;
    int i;
    cout << "Iniciou Black & White....";

    switch(type){
    //pino
    case 1:
    LIMIAR = 120;
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            Image.ReadPixel(x,y,r,g,b);

            if (i < LIMIAR)
            {
                NewImage.DrawPixel(x, y,0,0,0);
            }
            else NewImage.DrawPixel(x, y, 255,255,255);

        }
    }
    break;
    //canal
    case 2:
    LIMIAR = 50;
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            Image.ReadPixel(x,y,r,g,b);

            if (i < LIMIAR)
            {
                NewImage.DrawPixel(x, y,0,0,0);  // exibe um ponto PRETO na imagem
            }
            else NewImage.DrawPixel(x, y, 255,255,255); // exibe um ponto VERMELHO na imagem

        }
    }
    break;
    //pino
    case 3:
    LIMIAR = 30;
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            Image.ReadPixel(x,y,r,g,b);

            if (i < LIMIAR)
            {
                NewImage.DrawPixel(x, y,0,0,0);  // exibe um ponto PRETO na imagem
            }
            else NewImage.DrawPixel(x, y, 255,255,255); // exibe um ponto VERMELHO na imagem

        }
    }
    break;


    }
    //NewImage.CopyTo()
    cout << "Concluiu Black & White." << endl;
}

// **********************************************************************
// void DetectImageBorders()
// **********************************************************************
void DetectImageBorders()
{
    cout << "Iniciou DetectImageBorders...." << endl;

    cout << "Concluiu DetectImageBorders." << endl;

}

// **********************************************************************
// void ConvertToGrayscale()
// **********************************************************************
void ConvertToGrayscale()
{
    cout << "Iniciou ConvertToGrayscale..." << endl;
    int x,y;
    int i;
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // Le o TOM DE CINZA DA IMAGEM
            NewImage.DrawPixel(x, y,i,i,i);  // exibe um ponto CINZA na imagem da direita
        }
    }
    cout << "Concluiu ConvertToGrayscale." << endl;
}

// **********************************************************************
// void InvertImage()
// **********************************************************************
void InvertImage()
{
    cout << "Iniciou InvertImage..." << endl;

    cout << "Concluiu InvertImage." << endl;
}

void VerificaIntensidadeVetor(int vetor[500],int tipo){
    int temp, i , j;
    int aux = 0;
    //cout<< "<VETOR> \n";
    if(tipo == 1){
        for(i = 0; i < 49; i++)
        {
          if(vetor[i] > LIMIAR) aux++;
        }

        if(aux > 30){
            bPreenche = true;
        }else{
            bPreenche = false;
        }

    }else if(tipo == 2){
        for(i = 0; i < 100; i++)
        {
          LimiarDentinaMin = 30;
          LimiarDentinaMax = 100;
          if(vetor[i] > LimiarDentinaMin && vetor[i] < LimiarDentinaMax) aux++;
        }

        if(aux > 60){
            bPreenche = true;
        }else{
            bPreenche = false;
        }
    }else if(tipo == 3){


        if(aux > 8){
            bPreenche = true;
        }else{
            bPreenche = false;
        }
    }

}

void VerificaIntensidadeVetorOtimizado(int vetor[200]){
    int temp, i , j;
    int aux = 0;
        for(i = 0; i < 150; i++)
        {
          if(vetor[i] == 255) aux++;
          //cout << vetor[i] << endl;
        }
        //cout << vetor[i] << endl;
        if(aux > 60){
            bPreenche = true;
        }else{
            bPreenche = false;
        }
}
void VerificaIntensidadeVetorOtimizadoV2(int vetor[200]){
    int temp, i , j;
    int aux = 0;
        for(i = 0; i < 50; i++)
        {
          if(vetor[i] == 255) aux++;
          //cout << vetor[i] << endl;
        }

        if(aux > 35){
            bPreenche = true;
        }else{
            bPreenche = false;
        }
}

void VerificaIntensidadeVetorLinhaOtimizado(int vetor[81]){
    int temp, i , j;
    int aux = 0;
        for(i = 0; i < 81; i++)
        {
          if(vetor[i] == 255) aux++;
        }
        //cout << endl;
        if(aux > 40){
            bPreenche = true;
        }else{
            bPreenche = false;
        }
}

void VerificaIntensidadeVetorLinhaFiltro(int vetor[1000]){
    int temp, i , j;
    int aux = 0;
        for(i = 0; i < 861; i++)
        {
          if(vetor[i] == 255) aux++;
        }
        //cout << endl;
        if(aux > 225){
            bPreenche = true;
        }else{
            bPreenche = false;
        }
}

void VerificaIntensidadeVetorUltimosRuidos(int vetor[1000]){
    int temp, i , j;
    int aux = 0;
        for(i = 0; i < 441; i++)
        {
          if(vetor[i] == 0) aux++;
        }
        //cout << aux << endl;
        if(aux > 200){
            bPintaPreto = true;
        }else{
            bPintaPreto = false;
        }
}

void VerificaIntensidadeVetorVerticalOtimizado(int vetor[1000]){
    int temp, i , j;
    int aux = 0;
        for(i = 0; i < 51; i++)
        {
          if(vetor[i] == 255) aux++;
        }
        //cout << endl;
        if(aux > 8){
            bPreenche = true;
        }else{
            bPreenche = false;
        }
}

void OrdenaVetor(int window[])
{
    int temp, i , j;
    for(i = 0; i < 9; i++)
    {
        temp = window[i];
        for(j = i-1; j >= 0 && temp < window[j]; j--)
        {
            window[j+1] = window[j];
        }
        window[j+1] = temp;
    }
}

void OrdenaVetorAux(int window[])
{
    int temp, i , j;
    for(i = 0; i < 15; i++)
    {
        temp = window[i];
        for(j = i-1; j >= 0 && temp < window[j]; j--)
        {
            window[j+1] = window[j];
        }
        window[j+1] = temp;
    }
}

void OrdenaVetorNewMediana(int window[])
{
    int temp, i , j;
    for(i = 0; i < 9; i++)
    {
        temp = window[i];
        for(j = i-1; j >= 0 && temp < window[j]; j--)
        {
            window[j+1] = window[j];
        }
        window[j+1] = temp;
    }
}


void MontaVetor(int Px, int Py, int Vetor[9])
{
    int x,y;
    int i = 0;
    for(y = Py - 1; y<= Py + 1; y++)
    {
        for(x = Px - 1; x <= Px + 1; x++)
        {
           //i = Image.GetPointIntensity(x,y);
           Vetor[i] = Image.GetPointIntensity(x,y);
           i++;
        }
    }
}

int CalculaMedia(int Vetor[]){
    int i;
    int soma = 0;
    int totalItens = 0;
    int media = 0;
    int currValue = 0;
    for(i = 0; i< 49; i++)
    {
        currValue = Vetor[i];
        soma = soma + currValue;
        totalItens++;
    }
    media = soma/totalItens;
    //cout << media << endl;
    return media;
}

void PreencheJanela(int Px, int Py, int Vetor[49])
{
    int x,y;
    int i = 0;
    int mediana;
    for(y = Py - 3; y<= Py + 3; y++)
    {
        for(x = Px - 3; x <= Px + 3; x++)
        {
           //i = Image.GetPointIntensity(x,y);
           Vetor[i] = Image.GetPointIntensity(x,y);
           //cout << Vetor[i] << endl;
           i++;
        }
    }

    //OrdenaVetorAux(Vetor);
    //mediana = Vetor[11];
    mediana = CalculaMedia(Vetor);
    for(y = Py - 3; y<= Py + 3; y++)
    {
        for(x = Px - 3; x <= Px + 3; x++)
        {
           NewImage.DrawPixel(x,y,mediana,mediana,mediana);
        }
    }

}

void MontaVetorNewMediana(int Px, int Py, int Vetor[9])
{
    int x,y;
    int i = 0;
    for(y = Py - 1; y<= Py + 1; y++)
    {
        for(x = Px - 1; x <= Px + 1; x++)
        {
           //i = Image.GetPointIntensity(x,y);
           Vetor[i] = NewImage.GetPointIntensity(x,y);
           cout << Vetor[i] << endl;
           i++;
        }
    }
}

void MontaVetorOtimizado(int Px, int Py, int Vetor[200])
{
    int x,y;
    int i = 0;
    for(y = Py - 5; y<= Py + 5; y++)
    {
        for(x = Px - 5; x <= Px + 5; x++)
        {
           //i = Image.GetPointIntensity(x,y);
           Vetor[i] = NewImage.GetPointIntensity(x,y);
           i++;
        }
    }
}


void MontaVetorOtimizadoV2(int Px, int Py, int Vetor[200])
{
    int x,y;
    int i = 0;
    for(y = Py - 5; y<= Py + 5; y++)
    {
        for(x = Px - 5; x <= Px + 5; x++)
        {
           //i = Image.GetPointIntensity(x,y);
           Vetor[i] = NewImage.GetPointIntensity(x,y);
           i++;
        }
    }
}

void MontaVetorLinhaOtimizado(int Px, int Py, int Vetor[81])
{
    int x,y;
    int i = 0;
    for(y = Py; y<= Py; y++)
    {
        for(x = Px - 40; x <= Px + 40; x++)
        {
           //i = Image.GetPointIntensity(x,y);
           Vetor[i] = NewImage.GetPointIntensity(x,y);
           i++;
           //cout << Vetor[i] << " - ";
        }
        //cout << endl;
    }

}

void MontaVetorLinhaFiltro(int Px, int Py, int Vetor[1000])
{
    int x,y;
    int i = 0;
    unsigned char r,g,b;
    for(x = Px - 10; x <= Px + 10; x++)
    {
        for(y = Py - 20; y<= Py + 20; y++)
        {

           NewImage.ReadPixel(x,y,r,g,b);
           Vetor[i] = b;
           //cout << Vetor[i] << "-";
           i++;
        }
    }
    //cout << i << endl;

}

void MontaVetorUltimosRuidos(int Px, int Py, int Vetor[1000])
{
    int x,y;
    int i = 0;
    unsigned char r,g,b;
    for(x = Px - 10; x <= Px + 10; x++)
    {
        for(y = Py - 10; y<= Py + 10; y++)
        {

           NewImage.ReadPixel(x,y,r,g,b);
           Vetor[i] = r;
           //cout << Vetor[i] << "-";
           i++;
        }
    }
    //cout << i << endl;

}




void MontaVetorVerticalOtimizado(int Px, int Py, int Vetor[1000])
{
    int x,y;
    int i = 0;
    unsigned char r,g,b;
    for(x = Px - 0; x <= Px +0; x++)
    {
        for(y = Py - 25; y<= Py + 25; y++)
        {
           NewImage.ReadPixel(x,y,r,g,b);
           Vetor[i] = r;
           //cout << Vetor[i] << "-";
           i++;
        }
    }
    //cout << i << endl;

}

void VerificaIntensidadeVetorRuidoDeFora(int vetor[100]){
    int temp, i , j;
    int aux = 0;
        for(i = 0; i < 20; i++)
        {
          if(vetor[i] == 0) aux++;
          //cout << vetor[i] << endl;
        }

        if(aux > 10){
            bPreenche = true;
        }else{
            bPreenche = false;
        }
}

void MontaVetorRuidoDeFora(int Px, int Py, int Vetor[100])
{
    unsigned char r,g,b;
    int x,y;
    int i = 0;
    int aux = 0;
    for(y = Py - 3; y<= Py + 3; y++)
    {
        for(x = Px - 1; x <= Px + 1; x++)
        {
           //i = Image.GetPointIntensity(x,y);
           //Vetor[i] = NewImage.GetPointIntensity(x,y);
           NewImage.ReadPixel(x,y,r,g,b);
           Vetor[i] = g;
           if(Vetor[i] == 0) aux++;
           //cout << Vetor[i] << endl;
           i++;
        }
    }

    //cout << aux << endl;
    if(aux > 10){
            bPreenche = true;
        }else{
            bPreenche = false;
        }
}

void MontaVetorRuido(int Px,int Py,int Vetor[1000],int tipo)
{
    int x,y;
    int i = 0;

    if(tipo == 1){
        for(y = Py; y<= Py; y++)
        {
            for(x = Px - 10; x <= Px + 10; x++)
            {
            //i = Image.GetPointIntensity(x,y);
            Vetor[i] = Image.GetPointIntensity(x,y);
            i++;
            }
        }
    }else if(tipo == 2){
        for(y = Py - 5; y<= Py + 5; y++)
        {
            for(x = Px - 5; x <= Px + 5; x++)
            {
            //i = Image.GetPointIntensity(x,y);
            Vetor[i] = Image.GetPointIntensity(x,y);
            i++;
            }
        }
    }else if(tipo == 3){
        for(y = Py; y<= Py; y++)
        {
            for(x = Px - 10; x <= Px + 10; x++)
            {
            //i = Image.GetPointIntensity(x,y);
            Vetor[i] = Image.GetPointIntensity(x,y);
            i++;
            }
        }
    }

}

// **********************************************************************
// void Mediana()
// **********************************************************************
void Mediana()
{
    cout << "Iniciou Mediana..." << endl;
    double mediana;
    int Vetor[9];
    int x,y;
    int cont = 0;
    while (cont < 5){

    for(x=1; x<Image.SizeX()-1; x++)
    {
        for(y=1; y<Image.SizeY()-1; y++)
        {
            MontaVetor(x,y, Vetor); // Coloca em VETOR os valores das intensidades ao redor do ponto x,y.
            OrdenaVetor(Vetor);
            mediana = Vetor[5];
            NewImage.DrawPixel(x,y,mediana,mediana,mediana);
            //NewImage[x][y] = mediana;
            //Image[x][y] = (float)mediana;
        }

    }
    //NewImage.CopyTo(&Image);
    cont++;
    }
    //cout << Image.SizeX() << "\n";
    //cout << Image.SizeY() << "\n";


    cout << "Concluiu Mediana." << endl;

}

void NewMediana()
{
    cout << "Iniciou Mediana..." << endl;
    double mediana;
    int Vetor[9];
    int x,y;
    int cont = 0;
    while (cont < 5){

    for(x=1; x<NewImage.SizeX()-1; x++)
    {
        for(y=1; y<NewImage.SizeY()-1; y++)
        {
            MontaVetorNewMediana(x,y, Vetor); // Coloca em VETOR os valores das intensidades ao redor do ponto x,y.
            OrdenaVetorNewMediana(Vetor);
            mediana = Vetor[5];
            NewImage.DrawPixel(x,y,mediana,mediana,mediana);
            //NewImage[x][y] = mediana;
            //Image[x][y] = (float)mediana;
        }

    }
    //NewImage.CopyTo(&Image);
    cont++;
    }
    //cout << Image.SizeX() << "\n";
    //cout << Image.SizeY() << "\n";


    cout << "Concluiu Mediana." << endl;

}


void PreencheRuidosPinos(){
    cout << "Iniciou PreencheRuidos..." << endl;
    int Vetor[50];
    int x,y;

    for(x=2; x<Image.SizeX()-2; x++)
    {
        for(y=2; y<Image.SizeY()-2; y++)
        {
            MontaVetorRuido(x,y, Vetor,1);
            VerificaIntensidadeVetor(Vetor,1);
            if(bPreenche){
                NewImage.DrawPixel(x,y,0,0,255);
            }else{
                NewImage.DrawPixel(x,y,0,0,0);
                bPreenche = true;
            }
        }
    }
    //NewImage.CopyTo(&Image);
    cout << "Concluiu PreencheRuidos." << endl;

}

void PreencheRuidosDentina(){
    cout << "Iniciou PreencheRuidosDentina..." << endl;
    int Vetor[500];
    int x,y;
    int cont = 0;
    for(x=5; x<Image.SizeX()-5; x++)
    {
        for(y=5; y<Image.SizeY()-5; y++)
        {
            MontaVetorRuido(x,y, Vetor,2);
            VerificaIntensidadeVetor(Vetor,2);
            if(bPreenche){
                NewImage.DrawPixel(x,y,255,255,255);
            }else{
                NewImage.DrawPixel(x,y,0,0,0);
                bPreenche = true;
            }
        }

    }
    //NewImage.CopyTo(&Image);
    cout << "Concluiu PreencheRuidosDentina." << endl;

}

void TransfereCorParaImagem(){

    unsigned char r,g,b;

    int x,y;
    int i;
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            //i = NewImage.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            NewImage.ReadPixel(x,y,r,g,b);

            if(r != 0){
                Image.DrawPixel(x,y,255,0,0);
            }else if(g != 0 ){
                Image.DrawPixel(x,y,0,255,0);
            }else if(b != 0){
                Image.DrawPixel(x,y,0,0,255);
            }
        }
    }
}

void PreenchePinos(){
    unsigned char r,g,b;
    int x,y;
    int i;
    PreencheRuidosPinos();
    //pinos
    for(x=0; x<NewImage.SizeX(); x++)
    {
        cout<< "\n";
        for(y=0; y<NewImage.SizeY(); y++)
        {
            i = NewImage.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            NewImage.ReadPixel(x,y,r,g,b);

            if(i > LIMIAR){
                NewImage.DrawPixel(x, y,0,0,255);
            }
            else{
                NewImage.DrawPixel(x, y, 0,0,0); // exibe um ponto VERMELHO na imagem
            }

        }
    }
}

void PreencheDentina(){
    unsigned char r,g,b;
    int x,y;
    int i;
    PreencheRuidosDentina();
    //dentinas
    for(x=0; x<Image.SizeX(); x++)
    {
        cout<< "\n";
        LimiarDentinaMin = 100;
        LimiarDentinaMax = 120;
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            Image.ReadPixel(x,y,r,g,b);

            if(i > LimiarDentinaMin && i < LimiarDentinaMax){
                NewImage.DrawPixel(x, y,0,255,0);
            }
            else{
                NewImage.DrawPixel(x, y, 0,0,0); // exibe um ponto VERMELHO na imagem
            }

        }
    }
}

void OtimizaLocalDentina(){
    int Vetor[200];
    int x,y;
    int cont = 0;
    for(x=5; x<NewImage.SizeX()-5; x++)
    {
        for(y=5; y<NewImage.SizeY()-5; y++)
        {
            MontaVetorOtimizado(x,y,Vetor);
            VerificaIntensidadeVetorOtimizado(Vetor);
            //VerificaIntensidadeVetor(Vetor,2);
            if(bPreenche){
                NewImage.DrawPixel(x,y,255,255,255);
            }else{
                NewImage.DrawPixel(x,y,0,0,0);
                bPreenche = true;
            }
        }

    }
}

void OtimizaLocalDentinaV2(){
    int Vetor[200];
    int x,y;
    int cont = 0;
    for(x=3; x<NewImage.SizeX()-3; x++)
    {
        for(y=3; y<NewImage.SizeY()-3; y++)
        {
            MontaVetorOtimizadoV2(x,y,Vetor);
            VerificaIntensidadeVetorOtimizadoV2(Vetor);
            //VerificaIntensidadeVetor(Vetor,2);
            if(bPreenche){
                NewImage.DrawPixel(x,y,0,255,0);
            }else{
                NewImage.DrawPixel(x,y,0,0,0);
                bPreenche = true;
            }
        }

    }
}

void OtimizaLinhaDentina(){
    int Vetor[81];
    int x,y;
    int cont = 0;
    for(x=40; x<NewImage.SizeX()-40; x++)
    {
        for(y=0; y<NewImage.SizeY(); y++)
        {
            MontaVetorLinhaOtimizado(x,y,Vetor);
            VerificaIntensidadeVetorLinhaOtimizado(Vetor);
            //VerificaIntensidadeVetor(Vetor,2);
            if(bPreenche){
                //NewImage.DrawPixel(x,y,255,255,255);
                NewImage.DrawPixel(x,y,255,0,0);
            }else{
                NewImage.DrawPixel(x,y,0,0,0);
                bPreenche = true;
            }
        }

    }
}

void OtimizaLocalMaiorFiltro(){
    int Vetor[1000];
    int x,y;
    int cont = 0;
    for(x=10; x<NewImage.SizeX()-10; x++)
    {
        for(y=20; y<NewImage.SizeY()-20; y++)
        {
            MontaVetorLinhaFiltro(x,y,Vetor);
            VerificaIntensidadeVetorLinhaFiltro(Vetor);
            if(bPreenche){
                //NewImage.DrawPixel(x,y,255,255,255);
                NewImage.DrawPixel(x,y,255,0,0);
            }else{
                NewImage.DrawPixel(x,y,0,0,0);
                bPreenche = true;
            }
        }

    }
}

void RemoveUltimosRuidos(){
    int Vetor[1000];
    int x,y;
    int cont = 0;
    unsigned char r,g,b;
    for(x=0; x<NewImage.SizeX()-1; x++)
    {
        for(y=0; y<NewImage.SizeY()-1; y++)
        {
            NewImage.ReadPixel(x,y,r,g,b);
            if(r == 255){
                    cout << "Encontrou vermelho: "<< r << endl;
                do{
                   NewImage.ReadPixel(x+1,y,r,g,b);
                   cont = cont + 1;
                }while(r == 255);
                cout << "SAIU AMEM SENHOR"<< r << endl;
                /*MontaVetorUltimosRuidos(x,y,Vetor);
                VerificaIntensidadeVetorUltimosRuidos(Vetor);
                if(bPintaPreto){
                    NewImage.DrawPixel(x,y,255,255,255);
                }*/
            }
        }

    }
    cout << cont << endl;
}

void OtimizaVerticalDentina(){
    int Vetor[1000];
    int x,y;
    for(x=0; x<NewImage.SizeX(); x++)
    {
        for(y=25; y<NewImage.SizeY()-25; y++)
        {
            MontaVetorVerticalOtimizado(x,y,Vetor);
            VerificaIntensidadeVetorVerticalOtimizado(Vetor);
            if(bPreenche){
                NewImage.DrawPixel(x,y,0,0,255);
            }else{
                NewImage.DrawPixel(x,y,0,0,0);
                bPreenche = true;
            }
        }

    }
    x = 0;
}

void RemoveRuidosDeFora(){
    int Vetor[100];
    int x,y;
    int cont = 0;
    for(x=1; x<NewImage.SizeX()-1; x++)
    {
        for(y=3; y<NewImage.SizeY()-3; y++)
        {
            MontaVetorRuidoDeFora(x,y,Vetor);
            //VerificaIntensidadeVetorRuidoDeFora(Vetor);
            if(bPreenche){
                NewImage.DrawPixel(x,y,0,0,0);
            }
        }

    }
}

void SegmentacaoPorLimiar(){
    //PreenchePinos();
    //================================
    //PreencheDentina();
    //================================
    //PreencheCanal();
    //================================
    TransfereCorParaImagem();



    /*for(x=0; x<NewImage.SizeX(); x++)
    {
        cout<< "\n";
        for(y=0; y<NewImage.SizeY(); y++)
        {
            i = NewImage.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            NewImage.ReadPixel(x,y,r,g,b);
            if(i > LIMIAR){
                NewImage.DrawPixel(x, y,0,0,255);
            }
            else{
                NewImage.DrawPixel(x, y, 0,0,0); // exibe um ponto VERMELHO na imagem
            }
        }
    }
    for(x=0; x<Image.SizeX(); x++)
    {
        cout<< "\n";
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            Image.ReadPixel(x,y,r,g,b);
            LimiarDentinaMin = 60;
            LimiarDentinaMax = 130;
            if(i < LimiarDentinaMax && i > LimiarDentinaMin){
                NewImage.DrawPixel(x, y,0,255,0);
            }
            if (i < LimiarDentina){
                NewImage.DrawPixel(x, y,0,255,0);
            }else if(i<LimiarCanal){
                NewImage.DrawPixel(x, y,255,0,0);
            }else if(i<LimiarPinos){
                NewImage.DrawPixel(x, y,0,0,255);
            }
            else{
                NewImage.DrawPixel(x, y, 255,255,255); // exibe um ponto VERMELHO na imagem
            }
        }
    }*/
    //NewImage.CopyTo()
    //TransfereCorParaImagem();

}


void SegmentacaoPorRegioes(){

}

void TesteFiltro(){
    int x,y;
    double mediana;
    int Vetor[49];
    for(x=3; x<Image.SizeX()-3; x++)
    {
        for(y=3; y<Image.SizeY()-3; y++)
        {
            PreencheJanela(x,y, Vetor); // Coloca em VETOR os valores das intensidades ao redor do ponto x,y.

            //NewImage[x][y] = mediana;
            //Image[x][y] = (float)mediana;
        }

    }
}


// **********************************************************************
//  void init(void)
// **********************************************************************
void init()
{
    int r;
    // Carrega a uma image
    string nome = "0647.png";
    //string nome = "DadosOriginais\\0654.png"
//    string nome = "Ruido2.bmp";

    string path = "";
// No Code::Blocks para MacOS eh necessario usar um path absoluto
// string path = "ArquivosCodeBlocks/Imagens/";

    nome =  path + nome;
    cout << "imagem a ser carregada: *" << nome << "*" << endl;
    r = Image.Load(nome.c_str()); // Carrega uma imagem


    if (!r) exit(1); // Erro na carga da imagem
    else cout << ("Imagem carregada!\n");

    // Ajusta o tamnho da imagem da direita, para que ela
    // passe a ter o mesmo tamnho da imagem recem carregada
    // Caso precise alterar o tamanho da nova imagem, mude os parâmetros
    // da na chamada abaixo
    NewImage.SetSize(Image.SizeX(), Image.SizeY(), Image.Channels());
    cout << "Nova Imagem Criada" << endl;

}
// **********************************************************************
//  void reshape( int w, int h )
//  trata o redimensionamento da janela OpenGL
// **********************************************************************
void reshape( int w, int h )
{

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    gluOrtho2D(0,w,0,h);

    // Set the clipping volume
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
// **********************************************************************
//  void display( void )
// **********************************************************************
void display( void )
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Fundo de tela preto
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

// Ajusta o ZOOM da imagem para que apareca na metade da janela
    float zoomH = (glutGet(GLUT_WINDOW_WIDTH)/2.0)/(double)Image.SizeX();
    float zoomV = (glutGet(GLUT_WINDOW_HEIGHT))/(double)Image.SizeY();
    Image.SetZoomH(zoomH);
    Image.SetZoomV(zoomV);
// posiciona a imagem no canto inferior esquerdo da janela
    Image.SetPos(0, 0);

// posiciona a imagem nova na metada da direita da janela
    NewImage.SetPos(glutGet(GLUT_WINDOW_WIDTH)/2, 0);

// Ajusta o ZOOM da imagem para que apareca na metade da janela
    NewImage.SetZoomH(zoomH);
    NewImage.SetZoomV(zoomV);

// Coloca as imagens na tela
    Image.Display();
    NewImage.Display();

// Mostra a tela OpenGL
    glutSwapBuffers();
}
// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
// **********************************************************************
void keyboard ( unsigned char key, int x, int y )
{

    switch ( key )
    {
    case 27: // Termina o programa qdo
        NewImage.Delete();
        Image.Delete();
        exit ( 0 );   // a tecla ESC for pressionada
        break;
    case '2':
        ConvertBlackAndWhite(1);
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;

    case 'g':
        ConvertToGrayscale();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;

    case 'b':
        DetectImageBorders();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
    case 'i':
        InvertImage();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
     case 'm':
        Mediana();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
     case 'l':
        SegmentacaoPorLimiar();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
     case 'r':
        SegmentacaoPorRegioes();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
     case 'n':
         //NewMediana();

        break;
     case 'p':
        //PreencheRuidosPinos();
        //TransfereCorParaImagem();
        PreencheRuidosDentina();
        OtimizaLocalDentina();
        OtimizaLinhaDentina();
        OtimizaVerticalDentina();
        OtimizaLocalMaiorFiltro();
        RemoveUltimosRuidos();
        //TransfereCorParaImagem();


        //PreencheRuidosCanal();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
     case 't':
        TesteFiltro();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;


    default:
        break;
    }
}

// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )
// **********************************************************************
void arrow_keys ( int a_keys, int x, int y )
{
    switch ( a_keys )
    {
    case GLUT_KEY_UP:       // When Up Arrow Is Pressed...
        break;
    case GLUT_KEY_DOWN:     // When Down Arrow Is Pressed...

        break;
    default:
        break;
    }
}

// **********************************************************************
//  void main ( int argc, char** argv )
// **********************************************************************

int main ( int argc, char** argv )
{
    glutInit            ( &argc, argv );

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowPosition (10,10);

    // Define o tamanho da janela gráfica do programa
    glutInitWindowSize  ( LARGURA_JAN, ALTURA_JAN);
    glutCreateWindow    ( "Image Loader" );

    init ();

    glutDisplayFunc ( display );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutSpecialFunc ( arrow_keys );
    //glutIdleFunc ( display );

    glutMainLoop ( );
    return 0;
}
