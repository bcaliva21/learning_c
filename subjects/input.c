#include <stdio.h>
#include <string.h>

int main(void)
{
	int age;
	float height;
	char name[100];

	printf("Enter your name: ");
	fgets(name, sizeof(name), stdin);

	name[strcspn(name, "\n")] = 0;

	printf("Enter your age: ");
	scanf("%d", &age);

	printf("Enter your height in meters: ");
	scanf("%f", &height);



	printf("Hello, %s!  You are %d years old, %.2f meters tall.\n", name, age, height);

	return 0;
}
