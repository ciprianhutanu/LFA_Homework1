#include <iostream>
#include <fstream>
#include <cstring>
#include <deque>

std::ifstream in;
std::ifstream inn;
std::ofstream out;

void construct_language(int l[][100], int v[], int& mx) {
    inn.open("language.in");

    char node1[5], node2[5], letter, aux[5], finalnode[256], *fn;
    int n1, n2;

    inn.getline(finalnode, 256, '\n');

    fn = strtok(finalnode, " ,");
    while (fn != NULL)
    {
        strcpy(aux, fn + 1);
        strcpy(fn, aux);
        v[(int)*fn - 48] = 1;
        fn = strtok(NULL, " ,");
    }

    while (inn >> node1 >> letter >> node2) {
        n1 = 0;
        n2 = 0;
        strcpy(aux, node1 + 1);
        strcpy(node1, aux);
        strcpy(aux, node2 + 1);
        strcpy(node2, aux);
        int power = 1;
        for (int i = 0; i < strlen(node1); i++)
            n1 = n1 * power + ((int)node1[i] - 48), power*=10;
        power = 1;
        for (int i = 0; i < strlen(node2); i++)
            n2 = n2 * power + ((int)node2[i] - 48), power *= 10;
        if (n1 > mx)
            mx = n1;
        if (n2 > mx)
            mx = n2;
        l[n1][n2] = (int)letter;
    }

    inn.close();
}

int main()
{
    char chr;
    int i, n, x, y = 0, l[100][100]={}, v[100]={};
    std::deque<int> d;

    n = -1;
    construct_language(l,v,n);

    in.open("word.in");

    x = 0;
    d.push_back(x);

    while (in >> chr) {
        for (i = 0; i <= n; i++)
            if (l[x][i] == (int)chr)
                d.push_back(i), y = i;
        x = y;
    }

    if (v[d.back()] == 1) {
        while (!d.empty()) {
            std::cout << d.front() << ' ';
            d.pop_front();
        }
    }
    else
        std::cout << "Cuvant invalid!";
        
    in.close();
    return 0;
}
