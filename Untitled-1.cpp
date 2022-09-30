#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int a[10][10] = {0};
int vis[10] = {0};
double ans = 0.0;

void add_term(int node, int num_node, int start)
{
    if (num_node >= 4 && node == start)
    {
        ans += 1.0 / (2.0 * (1.0 * num_node - 1.0));
    }
    else
    {
        for (int j = 1; j <= 6; j++)
        {
            if (a[node][j] == 1 && vis[j] == 0)
            {
                if (j == start && num_node >= 3)
                {
                    add_term(j, num_node + 1, start);
                }
                else if (j != start)
                {
                    vis[j] = 1;
                    add_term(j, num_node + 1, start);
                }
                vis[j] = 0;
            }
        }
    }
}

int main()
{
    a[1][2] = 1;
    a[1][4] = 1;
    a[1][5] = 1;
    a[1][6] = 1;
    a[2][3] = 1;
    a[2][4] = 1;
    a[3][4] = 1;
    a[3][6] = 1;
    a[4][6] = 1;
    a[4][5] = 1;
    a[5][6] = 1;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = i + 1; j <= 6; j++)
        {
            if (a[i][j] == 1)
                a[j][i] = 1;
        }
    }
    for (int i = 1; i <= 6; i++)
    {
        memset(vis, 0, sizeof(vis));
        add_term(i, 1, i);
    }
    cout << ans << endl;
    return 0;
}
