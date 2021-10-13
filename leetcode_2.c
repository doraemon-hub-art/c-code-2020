//将两个数组排序
void merge(int* A, int ASize, int m, int* B, int BSize, int n)
{
    int i = 0;
    int k = 0;
    int j = 0;
    //将数组B放入A内
    for (i = 0; i < n; i++)
    {
        A[m + i] = B[i];
    }
    for (k = 0; k < n + m - 1; k++)
    {
        for (j = 0; j < n + m - 1 - k; j++)
        {
            int c = 0;
            if (A[j] > A[j + 1])
            {
                c = A[j];
                A[j] = A[j + 1];
                A[j + 1] = c;
            }
        }
    }
}
//