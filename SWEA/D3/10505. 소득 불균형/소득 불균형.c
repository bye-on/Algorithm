#include <stdio.h>

int arr[10001];
int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        scanf("%d", &n);
        
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            int input;
            scanf("%d", &input);
            arr[i] = input;
            result += input;
        }
        
        int count = 0; float average = 0;
        for(int i = 0; i < n; i++)
        {
            average = (float)result / n;
            if(average >= arr[i])
                count++;
        }
        
        printf("#%d %d\n", test_case, count);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}