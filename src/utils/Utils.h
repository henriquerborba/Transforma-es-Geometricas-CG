#ifndef UfloatILS_H_INCLUDED
#define UfloatILS_H_INCLUDED

class Utils
{
public:
    // Função que retorna a multiplicação de duas matrizes do tipo float
    static void multplyMatrix(float **matrix1, float **matrix2, int lines1, int columns1, int columns2)
    {
        float **matrixResult = createMatrix(lines1, columns2);

        for (int i = 0; i < lines1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                matrixResult[i][j] = 0;
                for (int k = 0; k < columns1; k++)
                {
                    matrixResult[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        for (int i = 0; i < lines1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                matrix1[i][j] = matrixResult[i][j];
            }
        }

        deleteMatrix(matrixResult, lines1);
    }

    // Função que aloca uma matriz nxm
    static float **createMatrix(int lines, int columns)
    {
        float **matrix = new float *[lines];
        for (int i = 0; i < lines; i++)
        {
            matrix[i] = new float[columns];
        }
        return matrix;
    }

    // Função que desaloca uma matriz nxm
    static void deleteMatrix(float **matrix, int lines)
    {
        for (int i = 0; i < lines; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

#endif