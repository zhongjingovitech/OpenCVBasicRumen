// OpenCVBasicRumen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <tchar.h>


//1. 命名空间需要有，否则Mat不能使用
//2. 早期使用的是IplImage,CvMat数据结构来表示图像，都是C语言的结构，内存需要手动管理，后面改成了Mat
//3.OpenCV表示RGB是BGR的存储。
//4.OpenCV中有模板类Vec，定义了很多小向量
//5. 可以使用Mat_来简化操作
//6.读写图像 imread,imwrite


using namespace cv;

using namespace std;




int main()
{

	Mat M(10, 12, CV_8UC3, Scalar(0, 0, 255));
	cout << "M = " << endl << " " << M << endl;

	//使用at访问
	Vec3b v1;
	v1[0] = 128;
	v1[1] = 128;
	v1[2] = 128;
	M.at<Vec3b>(1, 1) = v1;

	cout << "M = " << endl << " " << M << endl;

	//好像下面这样不行，不知道为什么
	/*cout << "v1=" << v1(0) << "," << v1(1) << "," << v1(2) << endl;*/
	waitKey();

	Vec3b v2 = M.at<Vec3b>(1, 1);
	std::cout << "v2:" << v2 << endl;

	//使用迭代器
	MatIterator_<Vec3b> colorit, colorend;
	for (colorit = M.begin<Vec3b>(),colorend = M.end<Vec3b>(); colorit != colorend; ++colorit)
	{
		(*colorit)[0] = rand() % 255;
		(*colorit)[1] = rand() % 255;
		(*colorit)[2] = rand() % 255;
	}
	cout << "M = " << endl << " " << M << endl;

	//使用指针
	for (int i = 0; i < M.rows; i++)
	{
		Vec3b *p = M.ptr<Vec3b>(i);
		for (int j = 0; j < M.cols; j++)
		{
			p[j][0] = i % 255;
			p[j][1] = j % 255;
			p[j][2] = 0;
		}
	}
	cout << "M = " << endl << " " << M << endl;
	imshow("M", M);
	waitKey();
	cv::waitKey();

	M.row(2) = M.row(1);//把第一行赋值给第二行

	Mat A = Mat::eye(10, 10, CV_32S);
	Mat B = A(Range::all(), Range(1, 3));//提取1-3列
	Mat C = B(Range(5, 9), Range::all());//提取5-9行

	Mat R = Mat(10, 10, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(255));

	IplImage ipImage = R;//直接赋值
	CvMat cvImg = R;//也是直接赋值，但是要注意Mat对象不能提前释放。

	Mat img = imread("D:\\code\\OpenCVDemo\\OpenCVBasicRumen\\x64\\Debug\\org2.bmp",-1);
	if (img.empty())
	{
		cout << "image is null\n";
		return 1;
	}
	imshow("org2", img);


    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
