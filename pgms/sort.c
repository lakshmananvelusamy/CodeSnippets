#include<stdio.h>
#include<stdlib.h>

int ccnt, flag;
char C[10000];

void mergeSort(int *numbers, int *temp, char *c, int array_size)
{
  m_sort(numbers, temp, c, 0, array_size - 1);
}
 
 
void m_sort(int *numbers, int *temp, char *c, int left, int right)
{
  int mid;
 
  if (right > left)
  {
    mid = (right + left) / 2;
    m_sort(numbers, temp, c, left, mid);
    m_sort(numbers, temp, c, mid+1, right);
 
    merge(numbers, temp, c, left, mid+1, right);
  }
}
 
void merge(int *numbers, int *temp, char *c, int left, int mid, int right)
{
  int i, left_end, num_elements, tmp_pos;
 
  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;
 
  while ((left <= left_end) && (mid <= right))
  {
    if (numbers[left] <= numbers[mid])
    {
	c[ccnt] = '1';
	ccnt++;	
      temp[tmp_pos] = numbers[left];
      tmp_pos = tmp_pos + 1;
      left = left +1;
    }
    else
    {
	c[ccnt] = '2';
	ccnt++;	
      temp[tmp_pos] = numbers[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
    }
  }
 
  while (left <= left_end)
  {
    temp[tmp_pos] = numbers[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = numbers[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
  }
 
  for (i=0; i <= num_elements; i++)
  {
    numbers[right] = temp[right];
    right = right - 1;
  }
}

main()
{
	int a[10000], b[10000];
	char c[10000] = {0};
	
	int i = 0, t, j, n;
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
	scanf("%d", &t);
	for(j = 0; j < t; j++)
	{
		scanf("%d", &n);
		scanf("%s", C);
		for(i = 1; i <= n; i++)
		{
			a[i-1] = i;
		}
		flag = 0;
		printf("Case #%d: ", j+1);
		permut(a, 0, n);
		/*ccnt = 0;	
		mergeSort(a, b, c, 100);
		printf("\n");
		for(i = 0; i < ccnt; i++)
		{
			printf("%c ", c[i]);
		}
		printf("\n");
		for(i = 0; i < 100; i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");
		*/
	}
}

void swap(int *a, int *b)
{
        int t = *a;
        *a = *b;
        *b = t;
}

int checksum(int *a, int n)
{
	int result = 1;
	int i;
	for (i = 0; i < n; i++)
	{
        	result = (31 * result + a[i]) % 1000003;
	}
    	return result;
}

void permut(int *s, int i, int n)
{
        int j;
        if (i == n)
        {
		char c[10000] = {0};
		int b[10000], A[10000], B[10000];
		ccnt = 0;
		int k = 0;
		for(k = 0; k < n; k++)
		{
                	B[k] = 	A[k] = s[k];
		}
		mergeSort(A, b, c, n);
		c[ccnt] = '\0';
		if (!strcmp(c, C))
		{
			printf("%d\n", checksum (B, n));
			flag = 1;
		}
                return;
        }
        for (j = i; j < n; j++)
        {
                swap(s + i, s + j);
                permut(s, i+1, n);
		if (flag)
		{
			return;
		}
                swap(s + j, s + i);
        }
}

