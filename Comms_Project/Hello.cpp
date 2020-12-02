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
#define _CRT_SECURE_NO_WARNINGS

int test() {
	
	cout << "Hello World\n";
	//char ch;
	FILE* JpgFile;
	int out;
	//char filename[45] = "C:\\Users\\ldill\\Desktop\\camera.jpg";
	 //fopen_s(&JpgFile,".\Resource Files\Jpeg_Grey.jpg", "rb");
	fopen_s(&JpgFile, "Jpeg_Grey.jpeg", "rb");
	//JpgFile=fopen(filename, "rb");
	//ifstream image("C:\\Users\\ldill\\Desktop\\camera.jpg");
	
	//fopen_s(&JpgFile, "C:/Users/ldill/Desktop/Example.jfif", "r");
	 if (JpgFile == NULL)
	 {
		 cout << "Error Reading the Image";
		 fclose(JpgFile);
		
	 }

	 //struct stat stat_buf;
	 //int rc=fstat(JpgFile,&stat_buf)

		 cout << "\nGot the image open\n";
		 cout << JpgFile;
		
		fscanf_s(JpgFile, "%d", &out);
		cout << "\noutput is" << out;

		unsigned char bytes[3];

		fread(bytes, 3, 1, JpgFile);
		cout << "\n";
		cout << bytes[0]<<"\n";
		cout << bytes[1]<<"\n";
		cout << bytes[2]<<"\n";

		if (bytes[0] == 0xff
			&& bytes[1] == 0xd8
			&& bytes[1] == 0xff) {

			printf_s("\nThis Image is "
				"in JPEG format!");
		}
		else {
			cout << "This is not a JPeg for some reason\n";
		}

		
		
		struct jpeg_decompress_struct cinfo;
		struct jpeg_error_mgr jerr;
	
		JSAMPROW row_pointer[1];

		if (!JpgFile)
		{
			cout << "This is an issue";
		}


		cinfo.err = jpeg_std_error(&jerr);

		jpeg_create_decompress(&cinfo);

		jpeg_stdio_src(&cinfo, JpgFile);

		//cout << cinfo;
		cout << JpgFile;

		jpeg_read_header(&cinfo, TRUE);
		cout << "here";

		printf_s("Width: %d  Height: %d",  cinfo.image_width, cinfo.image_height);
		cout << "File Info \n" << "Width: " << cinfo.image_width << "  Height: " << cinfo.image_height;
		cout << "\nColours per Pixel: " << cinfo.num_components;
		cout << "\nColour Space :" << cinfo.jpeg_color_space;

	 
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
		
		return 1;
}