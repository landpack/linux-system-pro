#include <stdio.h>

int
main(void) {
	unsigned char *p = "$123\r\n";
	int len = 0;
	
	p++; // ignore prefix `$`
	while (*p != '\r') {
		len = (len*10) + (*p - '0');
		printf("len = %d\t*p - '0' ==> %d\n",len,  *p - '0');
		p++;
	}

	/* Now p points at '\r', and the len is in bulk_len. */
	printf("%d\n", len);
	return 0;
}
