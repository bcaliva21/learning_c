#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm time_b =  {
		.tm_year=82,
		.tm_mon=3,
		.tm_mday=12,
		.tm_hour=4,
		.tm_min=00,
		.tm_sec=04,
		.tm_isdst=-1,
	};

	time_t now;
	time(&now);
	printf("%s\n", ctime(&now));

	time_t cal_b = mktime(&time_b);
	double diff = difftime(now, cal_b);
	double years = diff / 60 / 60 / 24 / 365.2425;

	printf("%f seconds (%f years) between events\n", diff, years);
}

