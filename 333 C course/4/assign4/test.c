// TCSS 333 - assignment4
// Zhihao Yang

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

unsigned long getFileSize(char *);
void processFileData(FILE *, FILE *, unsigned long, unsigned long);
void createblend(char *, char *, unsigned long, unsigned long);
void createchecker(char *, char *, unsigned long, unsigned long);

int main(int argc, char **argv) {

	FILE *f1;
	FILE *f2;
	unsigned long filesize1;
	unsigned long filesize2;
	int goForIt = 0;

	if (argc < 3) {
		printf("ERROR! Not enough arguments!\n");
	} else if (argc > 3){
		printf("ERROR! Too many arguments!\n");
	} else {

		// goForIt = checkFile(argv);
		// look up the first input file
		argv++;
		if ((long)(filesize1 = getFileSize(*argv)) < 0)
			printf("ERROR! %s cannot be accessed!\n", *argv);
		else
			f1 = fopen(*argv, "rb");   // read file in binary if it's valid

		// look up the second input file
		argv++;
		if ((long)(filesize2 = getFileSize(*argv)) < 0) 
			printf("ERROR! %s cannot be accessed!\n", *argv);
		else
			f2 = fopen(*argv, "rb");  // read file in binary if it's valid
			goForIt = 1;
		
	}

	if (goForIt) {
		// printf("Success1!\n");
		processFileData(f1, f2, filesize1, filesize2);

	}

	fclose(f1);
	fclose(f2);

	return 0;
}

// check whether the data in both file is valid and useable
void processFileData(FILE *f1, FILE *f2, unsigned long filesize1, unsigned long filesize2) {
	char *fileData1;
	char *fileData2;
	char *fileType1;
	char *fileType2;
	// open up some memory space for two files
	fileData1 = (char *)malloc(filesize1);
	fileData2 = (char *)malloc(filesize2);

	// read two files
	fread(fileData1, filesize1, 1, f1);
	fread(fileData2, filesize2, 1, f2);
	fileType1 = (char *)fileData1;
	fileType2 = (char *)fileData2;

	if (*fileType1 == 'B' && *(fileType1 + 1) == 'M') {
		if (*fileType2 == 'B' && *(fileType2 + 1) == 'M') {

			if (filesize1 == filesize2 && (filesize1 - 54) % 8 == 0) {
				createblend(fileData1, fileData2, filesize1, filesize2);
				createchecker(fileData1, fileData2, filesize1, filesize2);
			} else
				printf("ERROR! File1 and File2's sizes do not meet requirement!\n");
		}
		else
			printf("ERROR! File2 is not a BM format!\n");
	} else 
		printf("ERROR! File1 is not a BM format!\n");


	free(fileData1);
	free(fileData2);
}

// create blend image file
void createblend(char *data1, char *data2, unsigned long filesize1, unsigned long filesize2) {

	FILE *outfile1 = fopen("blend.bmp", "wb");

	char *header1 = (char *)data1;
	char *header2 = (char *)data2;
	char *pixels1 = (char *)data1 + 54;
	char *pixels2 = (char *)data2 + 54;

	// create the blend file
	char *blendpixels = (char*)malloc(filesize1);
	char *temp = (char *)blendpixels;
	int i, j;
	for (i = 0; j < 54; j++, temp++, header1++) {
		*temp = *header1;
	}
	for (j = 0; j < filesize1 - 54; j++, temp++, pixels1++, pixels2++) {
		// unsigned char mix = ((unsigned char)*pixels1 + (unsigned char)*pixels2) / 2;
		*temp = *pixels1;
	}
	
	fwrite(blendpixels, filesize1, 1, outfile1);
	fclose(outfile1);
	free(blendpixels);

}

// create checker image file
void createchecker(char *data1, char *data2, unsigned long filesize1, unsigned long filesize2) {
	// create the checker file
	FILE *outfile2 = fopen("cheker.bmp", "wb");
	char *head1 = (char *)data1;
	unsigned char *pixel1 = (unsigned char *)data1 + 54;
	unsigned char *pixel2 = (unsigned char *)data2 + 54;

	unsigned char *checkerpixels = (unsigned char*)malloc(filesize1);
	unsigned char *chktemp = (unsigned char *)checkerpixels;
	int *row, *col, i, j, k;
	// get the row and col info from header
	row = (int *)(data2 + 18);
	col = (int *)(data2 + 18 + sizeof(int));
	// printf("row:%d col:%d\n", *row, *col);
	for (i = 0; j < 54; j++, chktemp++, head1++) {
		*chktemp = *head1;
	}
	int rowgap = *row / 8;
	int colgap = *col * 3 / 8;
	// printf("rowgap:%d colgap:%d\n", rowgap, colgap);
	for (j = 0; j < *row; j++) {
		for (k = 0; k < *col*3; k++, chktemp++, pixel1++, pixel2++) {

			if (j / rowgap % 2 == 0) {
                // fill in the pixels
                if (k / colgap % 2 == 0)
                    *chktemp = *pixel1;
                else
                	*chktemp = *pixel2;            

            } else {

                if (k / colgap % 2 == 1)
                    *chktemp = *pixel1;
                else 
                    *chktemp = *pixel2;
			}

		}
	}

	
	fwrite(checkerpixels, filesize1, 1, outfile2);
	fclose(outfile2);
	free(checkerpixels);


}

// get the file size before accessing the file
unsigned long getFileSize(char *s) {
	long result = -1;
    struct stat file_info;
    if (stat(s, &file_info) > -1)
    {
        result = (unsigned long)(file_info.st_size);
    }
    return (unsigned long)result;
}