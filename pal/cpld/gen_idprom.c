#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	unsigned char data[32] = {
				  0x01, /* 0 = format */
				  0x11, /* 1 = machine type */
				  0x08, /* 2..7 = MAC addr (6 bytes) */
				  0x00,
				  0x20,
				  0x11,
				  0x22,
				  0x33,
				  0x23, /* 8..11 = Date (4 bytes) */
				  0x14,
				  0x91,
				  0xce,
				  0x01, /* 12..14 = SN# (3 bytes) */
				  0x70,
				  0xdb,
				  0xf3, /* 15 = checksum */
				  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* RSVD (16 bytes) */ 
				  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	};
	int i, j;
	int started = 0;

	for (i = 0 ; i < 8 ; i++) {
		printf("BIT%d = ", i);
		started = 0;
		for (j = 0 ; j < 32 ; j++) {
			if (data[j] & (1 << i)) {
				if (started) {
					printf(" # ");
				}
				started = 1;
				printf("(%sA0 & %sA1 & %sA2 & %sA3 & %sA4)",
				       (j & 0x01) ? " " : "!",
				       (j & 0x02) ? " " : "!",
				       (j & 0x04) ? " " : "!",
				       (j & 0x08) ? " " : "!",
				       (j & 0x10) ? " " : "!"
				       );
			}
		}
		if (started) printf(";\n");
		else printf(" 0;\n");
	}

	return 0;
}
