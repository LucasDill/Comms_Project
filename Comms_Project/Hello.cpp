#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
using namespace std;
using namespace cv;
int main() {
	cout << "Hello World\n";
	//char ch;
	FILE *JpgFile;
	int out;
	 //fopen_s(&JpgFile,".\Resource Files\Jpeg_Grey.jpg", "rb");
	fopen_s(&JpgFile, "C:/Users/ldill/Desktop/Jpeg_Grey.jpeg", "rb");
	 if (JpgFile == NULL)
	 {
		 cout << "Error Reading the Image";
		 fclose(JpgFile);
		
	 }

	 //struct stat stat_buf;
	 //int rc=fstat(JpgFile,&stat_buf)

		 cout << "Got the image open";
		 cout << JpgFile;
		
		fscanf_s(JpgFile, "%d", &out);
		cout << "output is" << out;
		
		
		struct jpeg_decompress_struct cinfo;
		struct jpeg_error_mgr jerr;
	
		JSAMPROW row_pointer[1];

		if (!JpgFile)
		{
			cout << "This is an issue";
		}


		//cinfo.err = jpeg_std_err(&jerr);

		jpeg_create_decompress(&cinfo);

		jpeg_stdio_src(&cinfo, JpgFile);

		//cout << cinfo;
		cout << JpgFile;
/*
		jpeg_read_header(&cinfo, TRUE);
		cout << "here";

		printf_s("Width: %d  Height: %d",  cinfo.image_width, cinfo.image_height);
		cout << "File Info \n" << "Width: " << cinfo.image_width << "  Height: " << cinfo.image_height;
		cout << "\nColours per Pixel: " << cinfo.num_components;
		cout << "\nColour Space :" << cinfo.jpeg_color_space;
*/
	 /*
		//////////////////////////////////////////////////////////////USING OPEN CV
		Mat img = imread("C:/Users/ldill/Desktop/Jpeg_Grey.jpeg", IMREAD_COLOR);
		if (img.empty())
		{
			cout << "Could not read the image";
		}
		imshow("Display window", img);
		cout << img;
		int k = waitKey(0);

		//if (k == 's')
		//{
			imwrite("C:/Users/ldill/Desktop/Bitmap_Grey.bmp", img);
		//}
		*/
}