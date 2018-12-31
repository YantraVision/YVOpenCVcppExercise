
// Compile with: $ g++ GstCvPlayvideo.cpp -o GstCvPlayvideo `pkg-config --cflags --libs opencv`
// export GST_PLUGIN_PATH=/usr/local/lib/gstreamer-1.0

#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) 
{
    cv::VideoCapture cap("filesrc location=SampleVideo_1280x720_1mb.mp4 ! decodebin ! videoconvert ! myfilter ! appsink");

    if(!cap.isOpened())
    {
        printf("VideoCapture  not opened \n");
        exit(-1);
    }

    cv::VideoWriter out("appsrc ! myfilter ! udpsink host=127.0.0.1 port=5000",0,30,cv::Size(640,480),true);

    if( !out.isOpened())
    {
        printf("VideoCapture or VideoWriter not opened \n");
        exit(-1);
    }

    cv::Mat frame;

    while(true) {

        cap.read(frame);

        if(frame.empty())
            break;

        out.write(frame);

        imshow("Sender", frame);
        if(cv::waitKey(1) == 's')
            break;
    }
    cv::destroyWindow("Sender");


    return 0;
}
