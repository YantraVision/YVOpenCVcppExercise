Steps to build and execute the app
-----------------------------------

$ g++ GstCvPlayvideo.cpp -o GstCvPlayvideo `pkg-config --cflags --libs opencv`
$ export GST_PLUGIN_PATH=/usr/local/lib/gstreamer-1.0
$ ./GstCvPlayvideo
