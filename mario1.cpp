// cmmM = cea mai mare valoare a lui Mario
// cmmB = cea mai mica valoare a lui Bowser

#include <iostream>
#include <fstream>
#define max 1000

using namespace std;

int N, M, k = 0, listafinal1[max], listafinal2[max];
ifstream fin("mario.in");
ofstream fout("mario.out");

int main()
{
    fin >> N;
    int m[N];
    for (int i = 0; i < N; i++) fin >> m[i];
    fin >> M;
    int b[M];
    for (int i = 0; i < M; i++) fin >> b[i];



    while (true)
    {
        int cmmM = 0, cmmB = 10000, idI, idJ;
        int i, j;
        for (i = 0; i < N; i++)
        {
            if (m[i] > cmmM) {
                cmmM = m[i];
                idI = i;
            }
        }
        for (j = 0; j < M; j++)
        {
            if (b[j] < cmmB) {
                cmmB = b[j];
                idJ = j;
            }
        }
        if (cmmM > cmmB)
        {
            k++;
            listafinal1[k-1] = idI + 1;
            listafinal2[k-1] = idJ + 1;
            m[idI] = cmmB;
            b[idJ] = cmmM;
        }
        else
        {
            break;
        }
    }

    fout << k << endl;
    for (int i = 0; i < k; i++)
    {
        fout << listafinal1[i] << " " << listafinal2[i] << endl;
    }

    fout.close();
    return 0;
}