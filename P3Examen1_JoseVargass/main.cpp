/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: josevargas
 *
 * Created on November 20, 2020, 12:54 PM
 */

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


//Provisionar la matriz de chars para el tablero
char** provisionarMatriz(int, int);

char** provisionarMatriz2(int, int);

//liberar memoria de la matriz
void liberarMatriz(char**&,int);

//imprimir la matriz
void printMatrix(char**,int, int);

/*
 * 
 */
int main(int argc, char** argv) {
    
    bool valid = true;
    while(valid){
        char** tablero=NULL;
        int opcion = 0;
        cout << "               MENU" << endl
                << "1. Jugar con un tablero aleatorio" << endl
                << "2. Jugar con un tablero predefinido" << endl
                << "3. Salir" << endl
                << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:{
                int x=0, y=0, celulas=0, n_gen = 0;
                cout << "Ingrese el numero de filas del tablero: ";
                cin >> x;
                cout << "Ingrese el numero de columnas del tablero: ";
                cin >> y;
                cout << "Ingrese el numero de celulas vivas iniciales: ";
                cin >> celulas;
                cout << "Ingrese el numero de generaciones a simular: ";
                cin >> n_gen;
                tablero=provisionarMatriz(x, y);
                liberarMatriz(tablero,x);
                break;
            }
            case 2:{
                int n_gen2 = 0;
                cout << "Ingrese el numero de generaciones a simular: ";
                cin >> n_gen2;
                tablero=provisionarMatriz2(20, 20);
                printMatrix(tablero, 20, 20);
                liberarMatriz(tablero,20);
                break;
            }
            case 3:{
                valid = false;
                break;
            }
        }
        
    }
    return 0;
}

void liberarMatriz(char**& matrix,int size){
    if(matrix != NULL){
        for(int i = 0; i < size; i++){
            if(matrix[i] != NULL){
                delete[] matrix[i];
            }
            matrix[i] = NULL;
        }
    }
    
    if(matrix != NULL){
        delete[] matrix;
        matrix = NULL;
    }
}

void printMatrix(char** matrix, int x, int y){
    
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

char** provisionarMatriz(int filas, int columnas){
    //declarar
    char** letters = NULL;
    //instanciar
    letters = new char*[filas];          //primero arreglo (de filas) de char*
    
    for(int i=0; i < filas; i++)
        letters[i] = new char[columnas];    //despues arreglo (de columnas) de chars
        
    //inicializar 
    for(int i = 0; i< filas; i++)
        for(int j = 0; j<columnas ; j++)
            letters[i][j] = '.';
    
    return letters;
}

char** provisionarMatriz2(int filas, int columnas){
    int temp_mat [20][20] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0}, {0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0}, {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
    int ** mat = new int*[columnas]; 
    for(int i = 0; i < columnas ; i++){
        mat[i] = new int[filas]; 
        for(int j = 0; j < filas ; j++){
            mat[i][j] = temp_mat[i][j]; 
        }
    }
    return mat;
}

