#include <stdio.h>
int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
        int A, B;
		scanf("%d %d", &A, &B);
        int result = (A+B) % 24;
        printf("#%d %d\n", test_case, result);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}