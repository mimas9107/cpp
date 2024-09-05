#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main(int argc, char* argv[]){
    if(argc==1) return 0L;
    Mat img = imread(argv[1], IMREAD_GRAYSCALE);
    if (!img.data){
        return -1;
    }

    std::cout << "======== info ========" << endl;    
    std::cout << "rows= " << img.rows << endl;
    std::cout << "cols= " << img.cols << endl;
    Size size = img.size();
    std::cout << "Size= " << size << endl;
    std::cout << "channels= " << img.channels() << endl;

    std::cout << "Area= " << img.total() << endl;

    std::cout << "dim= " << img.dims << endl;
    std::cout << "======================" << endl;

    // for(int r=0; r < img.rows; r++){
    //     for(int c=0; c < img.cols; c++){
    //         std:cout << img.at<int>(r,c) << ",";
    //     }
    //     cout << endl;
    // }
    
    // for(int r=0; r<img.rows; r++){
    //     const int *ptr = img.ptr<int>(r);
    //     for(int c=0; c<img.cols; c++){
    //         std::cout << ptr[c] << ";";

    //     }
    //     std::cout << endl;
    // }

    imshow("orig", img);
    waitKey(0);
}