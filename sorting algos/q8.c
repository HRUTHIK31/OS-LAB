#include<stdio.h>
#include<math.h>
#include<pthread.h>
float a[25][25],fac[25][25];
float determinant(float [][25], int);
void *runcofactor(void *param);
void *transpose(void *param);
int main()
{
	float d;
	int i, j, k;
	printf("Enter the order of the Matrix : ");
	scanf("%d", &k);
	printf("Enter the elements of %d X %d Matrix : \n", k, k);
	for (i = 0;i < k; i++)
	{
		for (j = 0;j < k; j++)
			scanf("%f", &a[i][j]);
	}
	printf("\nMatrix A is:\n\t");
	for (i = 0;i < k; i++)
	{
		for (j = 0;j < k; j++)
			printf("%.0f\t", a[i][j]);
		printf("\n\t");
	}
    d = determinant(a, k);
    if (d == 0)
    	printf("\n\nInverse of Entered Matrix is not possible\n");
    else
    {
    	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runcofactor, k);
	pthread_join(tid, NULL);
        pthread_create(&tid, &attr, transpose, k);
	pthread_join(tid, NULL);
    }
    return 0;
}
float determinant(float a[25][25], int k)
{
	float s = 1, det = 0, b[25][25];
	int i, j, m, n, c;
	if (k == 1)
	{
		return (a[0][0]);
	}
	else
	{
		det = 0;
		for (c = 0; c < k; c++)
		{
			m = 0;
			n = 0;
			for (i = 0;i < k; i++)
			{
				for (j = 0 ;j < k; j++)
				{
					b[i][j] = 0;
					if (i != 0 && j != c)
					{
						b[m][n] = a[i][j];
						if (n < (k - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (a[0][c] * determinant(b, k - 1));
			s = -1 * s;
		}
	}
	return (det);
}
void *runcofactor(void *param)
{
	int f = (int)param;
	float b[25][25];
	int p, q, m, n, i, j;
	for (q = 0;q < f; q++)
	{
		for (p = 0;p < f; p++)
		{
			m = 0;
			n = 0;
			for (i = 0;i < f; i++)
			{
				for (j = 0;j < f; j++)
				{
					if (i != q && j != p)
					{
						b[m][n] = a[i][j];
						if (n < (f - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			fac[q][p] = pow(-1,q+p) * determinant(b,f-1);
		}
	}
	pthread_exit(0);  
} 
void *transpose(void *param)
{ 
	int r = (int)param;
        int i, j;
	float b[25][25], inverse[25][25], d; 
	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
			b[i][j] = fac[j][i];
	}
	d = determinant(a, r);
	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
			inverse[i][j] = b[i][j] / d;
	}
	printf("\nThe inverse of matrix is : \n\t"); 
	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
			printf("%f\t", inverse[i][j]);
		printf("\n\t");
	}
        pthread_exit(0);  
}
