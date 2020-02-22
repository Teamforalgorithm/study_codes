#include <stdio.h>

int main(void)
{
	int number_of_N, L, ans = 0, x, y, c;
	short N[200][100];
	scanf("%d %d", &number_of_N, &L);
	for (y = 0; y < number_of_N; y++)
	{
		for (x = 0; x < number_of_N; x++)
		{
			scanf("%hd", &N[x][y]);
		}
	}
	for (y = 0; y < number_of_N; y++)
	{
		for (x = 0; x < number_of_N; x++)
		{
			N[x + number_of_N][y] = N[y][x];
		}
	}
	for (x = 0; x < number_of_N * 2; x++)
	{
		c = 1;
		for (y = 0; y < number_of_N - 1; y++)
		{
			if (N[x][y] == N[x][y + 1])
			{
				c++;
			}
			else if (N[x][y] + 1 == N[x][y + 1] && c >= L)
			{
				c = 1;
			}
			else if (N[x][y] - 1 == N[x][y + 1] && c >= 0)
			{
				c = -L + 1;
			}
			else
			{
				break;
			}
		}
		if (y == number_of_N - 1 && c >= 0)
		{
			ans++;
		}
	}
	printf("%d", ans);

	return 0;
}