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
#include <time.h> 

using std::cout;
using std::endl;
using std::cin;


//Provisionar la matriz de chars para el tablero
int** provisionarMatriz(int, int);

int** rellenarMatriz(int, int, int);

int** provisionarMatriz2(int, int);

//liberar memoria de la matriz
void liberarMatriz(int**&, int);

//imprimir la matriz
void printMatrix(int**, int, int);

int** conway(int**, int, int);

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(0));
    bool valid = true;
    while (valid) {
        int** tablero = NULL;
        int opcion = 0;
        cout << "               MENU" << endl
                << "1. Jugar con un tablero aleatorio" << endl
                << "2. Jugar con un tablero predefinido" << endl
                << "3. Salir" << endl
                << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
            {
                int x = 0, y = 0, celulas = 0, n_gen = 0;
                cout << "Ingrese el numero de filas del tablero: ";
                cin >> x;
                cout << "Ingrese el numero de columnas del tablero: ";
                cin >> y;
                cout << "Ingrese el numero de celulas vivas iniciales: ";
                cin >> celulas;
                cout << "Ingrese el numero de generaciones a simular: ";
                cin >> n_gen;
                tablero = provisionarMatriz(x, y);
                tablero = rellenarMatriz(x, y, celulas);
                cout << "Generacion 1: " << endl;
                printMatrix(tablero, x, y);
                for (int i = 1; i < n_gen; i++) {
                    cout << "PRESIONE ENTER PARA CONTINUAR" ;
                    if(i == 1)
                        cin.ignore();
                    cin.ignore();
                    cout << "Generacion " << i + 1 << endl;
                    tablero = conway(tablero, x, y);
                }
                liberarMatriz(tablero, x);
                cout << endl;
                break;
            }
            case 2:
            {
                int n_gen2 = 0;
                cout << "Ingrese el numero de generaciones a simular: ";
                cin >> n_gen2;
                tablero = provisionarMatriz2(20, 20);
                cout << "Generacion 1: " << endl;
                printMatrix(tablero, 20, 20);
                char continuar;
                for (int i = 1; i < n_gen2; i++) {
                    cout << "PRESIONE ENTER PARA CONTINUAR";
                    if(i == 1)
                        cin.ignore();
                    cin.ignore();
                    cout << "Generacion " << i + 1 << ": " << endl;
                    tablero = conway(tablero, 20, 20);
                }
                liberarMatriz(tablero, 20);
                cout << endl;
                break;
            }
            case 3:
            {
                valid = false;
                break;
            }
        }

    }
    return 0;
}

void liberarMatriz(int**& matrix, int size) {
    if (matrix != NULL) {
        for (int i = 0; i < size; i++) {
            if (matrix[i] != NULL) {
                delete[] matrix[i];
            }
            matrix[i] = NULL;
        }
    }

    if (matrix != NULL) {
        delete[] matrix;
        matrix = NULL;
    }
}

void printMatrix(int** matrix, int x, int y) {
    for(int h = 0; h < y +2; h++){
        cout << "# ";
    }
    cout << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (j == 0 ) {
                if (matrix[i][j] == 0)
                    cout << "# . ";
                else
                    cout << "# * ";
            }else if(j == y -1){
                if (matrix[i][j] == 0)
                    cout << ". #";
                else
                    cout << "* #";
            }else{
                if (matrix[i][j] == 0)
                    cout << ". ";
                else
                    cout << "* ";
            }
        }
        cout << endl;
    }
    for(int k = 0; k < y + 2; k++){
        cout << "# ";
    }
    cout << endl;
}

int** provisionarMatriz(int filas, int columnas) {
    //declarar
    int** letters = NULL;
    //instanciar
    letters = new int*[filas]; //primero arreglo (de filas) de char*

    for (int i = 0; i < filas; i++)
        letters[i] = new int[columnas]; //despues arreglo (de columnas) de chars

    //inicializar 
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            letters[i][j] = 0;

    return letters;
}

int** provisionarMatriz2(int x, int y) {
    int temp_mat [20][20] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int ** mat = new int*[y];
    for (int i = 0; i < y; i++) {
        mat[i] = new int[x];
        for (int j = 0; j < x; j++) {
            mat[i][j] = temp_mat[i][j];
        }
    }
    return mat;

}

int** rellenarMatriz(int x, int y, int celulas) {
    int** temporal = NULL;
    int cont = 0;
    temporal = new int*[x];
    for (int i = 0; i < x; i++)
        temporal[i] = new int[y];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            temporal[i][j] = 0;
        }
    }

    int rand_x = 0, rand_y = 0;
    for (int i = 0; i < celulas; i++) {
        rand_x = rand() % x;
        rand_y = rand() % y;
        if (temporal[rand_x][rand_y] == 1)
            i -= 1;
        else
            temporal[rand_x][rand_y] = 1;
    }

    return temporal;
}

int** conway(int **mat, int x, int y) {
    int** temporal = NULL;
    temporal = provisionarMatriz(x, y);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int cel_vivas = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k + i < 0 || k + i >= x || l + j < 0 || l + j >= y) {

                    } else
                        cel_vivas += mat[k + i][l + j];
                }
            }
            cel_vivas -= mat[i][j];

            if ((mat[i][j] == 1) && (cel_vivas < 2))
                temporal[i][j] = 0;

            else if ((mat[i][j] == 1) && (cel_vivas > 3))
                temporal[i][j] = 0;

            else if ((mat[i][j] == 0) && (cel_vivas == 3))
                temporal[i][j] = 1;

            else
                temporal[i][j] = mat[i][j];
        }
    }

    printMatrix(temporal, x, y);
    return temporal;
}
