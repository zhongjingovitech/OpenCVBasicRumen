// OpenCVBasicRumen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>

//命名空间需要有，否则Mat
using namespace cv;
using namespace std;
int main()
{

	Mat M(3, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "M = " << endl << " " << M << endl;

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


	MatIterator_<Vec3b> colorit, colorend;
	for (colorit = M.begin<Vec3b>(),colorend = M.end<Vec3b>(); colorit != colorend; ++colorit)
	{
		(*colorit)[0] = rand() % 255;
		(*colorit)[1] = rand() % 255;
		(*colorit)[2] = rand() % 255;
	}
	cout << "M = " << endl << " " << M << endl;

	waitKey();

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
