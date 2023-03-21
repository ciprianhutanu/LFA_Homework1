#include <iostream>
#include <fstream>
#include <cstring>
#include <deque>

std::ifstream in;
std::ifstream inn;
std::ofstream out;

void construct_language(int l[][100], int v[], int& mx, int& firstchr, int& lastchr, int& sn) {
    inn.open("language.in");

    char node1[5], node2[5], letter, aux[5], finalnode[256], *fn, startnode[10];
    int n1, n2, power;

    firstchr = 256;
    lastchr = 0;

    inn.getline(finalnode, 256, '\n');

    fn = strtok(finalnode, " ,");
    power = 1;
    sn = 0;
    for (int i = 0; i < strlen(fn); i++)
        if ('0' <= fn[i] and fn[i] <= '9')
            sn = sn * power + ((int)fn[i] - 48), power *= 10;
    fn = strtok(NULL, " ,");
    while (fn != NULL)
    {
        power = 1;
        int finaln = 0;
        for (int i = 0; i < strlen(fn); i++)
            if ('0' <= fn[i] and fn[i] <= '9')
                finaln = finaln * power + ((int)fn[i] - 48), power *= 10;
        v[finaln] = 1;
        fn = strtok(NULL, " ,");
    }

    while (inn >> node1 >> letter >> node2) {
        n1 = 0;
        n2 = 0;
        power = 1;
        for (int i = 0; i < strlen(node1); i++)
            if('0' <= node1[i] and node1[i]<='9')
                n1 = n1 * power + ((int)node1[i] - 48), power*=10;
        power = 1;
        for (int i = 0; i < strlen(node2); i++)
            if ('0' <= node2[i] and node2[i] <= '9')
                n2 = n2 * power + ((int)node2[i] - 48), power *= 10;
        if (n1 > mx)
            mx = n1;
        if (n2 > mx)
            mx = n2;
        l[n1][(int)letter] = n2;
        if ((int)letter > lastchr)
            lastchr = (int)letter;
        if ((int)letter < firstchr)
            firstchr = (int)letter;
    }

    inn.close();
}

int main()
{
    char chr;
    int i, n, x, y = 0, l[100][100]={}, v[100]={}, fc, lc, sn;
    std::deque<int> d;

    n = -1;
    construct_language(l,v,n,fc,lc, sn);

    in.open("word.in");

    x = sn;
    d.push_back(x);

    while (in >> chr) {
        y = -1;
        if (x == -1) {
            d.push_back(x);
            break;
        }
        for (i = 0; i <= n; i++)
            if (l[x][(int)chr] == i)
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
