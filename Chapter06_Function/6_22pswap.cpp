void pswap(int *&a, int *&b)
{
    int *tmp = a;
    a = b;
    b = tmp;
}