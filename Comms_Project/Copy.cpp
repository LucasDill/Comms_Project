#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


typedef struct JpegComponent {
	int cid;
	int ssx, ssy;
	int width, height;
	int stride;
	int qtsel;
	int actabsel, dctabsel;
	int dcpred;
	unsigned char* pixels;
} JpegComponent;

typedef struct JpegCode {
	unsigned char bits, code;
}JpegCode;

typedef struct JpegStruct {
	const unsigned char* pos;
	int size;
	int length;
	int width, height;
	int mbwidth, mbheight;
	int mbsizex, mbsizey;
	int ncomp;
	JpegComponent comp[3];
	int qtused, qtavail;
	unsigned char qtab[4][64];
	JpegCode vlctab[4][65536];
	int buf, bufbits;
	int block[64];
	int rstinterval;
	unsigned char* rgb;
}JpegStruct;

static JpegStruct jpg;

int test1()
{
	int size;
	char* buf;
	FILE* f;

	fopen_s(&f, "C:/Users/ldill/Desktop/Jpeg_Grey.jpeg", "rb");

	if (!f)
	{
		cout << "Error getting the Image file\n";
	}
	fseek(f, 0, SEEK_END);
	size = (int)ftell(f);
	cout <<"Size of file "<< size;
	buf = (char*)malloc(size);
	fseek(f, 0, SEEK_SET);
	size = (int)fread(buf, 1, size, f);
	cout << "\nSize of Buffer " << size;
	

	cout<<"\nBuffer" << &buf;
	cout << "\nHERE";

	unsigned char bytes[3];

	fread(bytes, 3, 1, f);
	cout << "\n";
	cout << &bytes[0] << "\n";
	cout << &bytes[1] << "\n";
	cout << &bytes[2] << "\n";

	if (bytes[0] == 0xff
		&& bytes[1] == 0xd8
		&& bytes[1] == 0xff) {

		printf_s("\nThis Image is "
			"in JPEG format!");
	}
	else {
		cout << "This is not a JPeg for some reason\n";
	}
	fclose(f);

	
	int sizor= size & 0x7FFFFFFF; 
	cout << "\nWeird Size is " << sizor;

	typedef unsigned char  UInt8;
	typedef unsigned short UInt16;

	const UInt16 JFIF_BYTE_FF = 0xFF; // All markers start with this as the MSB                  
	const UInt16 JFIF_SOF0 = 0xC0; // Start of Frame 0, Baseline DCT                           
	const UInt16 JFIF_SOF1 = 0xC1; // Start of Frame 1, Extended Sequential DCT               
	const UInt16 JFIF_SOF2 = 0xC2; // Start of Frame 2, Progressive DCT                       
	const UInt16 JFIF_SOF3 = 0xC3; // Start of Frame 3, Lossless (Sequential)                 
	const UInt16 JFIF_DHT = 0xC4; // Define Huffman Table                                    
	const UInt16 JFIF_SOF5 = 0xC5; // Start of Frame 5, Differential Sequential DCT           
	const UInt16 JFIF_SOF6 = 0xC6; // Start of Frame 6, Differential Progressive DCT          
	const UInt16 JFIF_SOF7 = 0xC7; // Start of Frame 7, Differential Loessless (Sequential)   
	const UInt16 JFIF_SOF9 = 0xC9; // Extended Sequential DCT, Arithmetic Coding              
	const UInt16 JFIF_SOF10 = 0xCA; // Progressive DCT, Arithmetic Coding                      
	const UInt16 JFIF_SOF11 = 0xCB; // Lossless (Sequential), Arithmetic Coding                
	const UInt16 JFIF_SOF13 = 0xCD; // Differential Sequential DCT, Arithmetic Coding          
	const UInt16 JFIF_SOF14 = 0xCE; // Differential Progressive DCT, Arithmetic Coding         
	const UInt16 JFIF_SOF15 = 0xCF; // Differential Lossless (Sequential), Arithmetic Coding   
	const UInt16 JFIF_SOI = 0xD8; // Start of Image                                          
	const UInt16 JFIF_EOI = 0xD9; // End of Image                                            
	const UInt16 JFIF_SOS = 0xDA; // Start of Scan                                           
	const UInt16 JFIF_DQT = 0xDB; // Define Quantization Table
	const UInt16 JFIF_APP0 = 0xE0; // Application Segment 0, JPEG-JFIF Image
	const UInt16 JFIF_COM = 0xFE; // Comment

	cout << "\nHERE"<< JFIF_EOI;
	cout <<"\n HUFF TABLE" <<JFIF_DHT;
	cout << "\nFrame0 " << JFIF_SOF0;
	cout << "\nFrame1 " << JFIF_SOF1;
	cout << "\nFrame2 " << JFIF_SOF2;
	cout << "\nComment " << JFIF_COM;
	cout << "\nSegment 0 " << JFIF_APP0;
	cout << "\nmsb " << JFIF_BYTE_FF;
	return 1;
}

void FillMem(void* block, unsigned char value, int count) {
	_asm {
		mov edi,block
		mov al,value
		mov ecx,count
		rep stosb
} }