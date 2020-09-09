#ifndef OPTICAL_FLOW_H
#define OPTICAL_FLOW_H

#include <opencv2/opencv.hpp>

class OpticalFlow
{

public:

    OpticalFlow();

    /**
     * Constructor
    */
    OpticalFlow( int frame_width, int frame_height, int scaledown = 1, int interval = 16 );

    /**
     * Calculate pixel flow and convert to velocity (m/s) if distance is supplied
    */
    cv::Point2f process_frame( cv::Mat frame, float dt, float distance = 0 );

    cv::Mat get_frame( void );

private:

    cv::Mat frame;
    cv::Mat prev_frame;
    cv::Size size;

    int interval;
    
    
    /**
     * Compute optical flow in pixels / second. Sum is the total pixel change while count is the total number of points for the frame.
    */
    float compute_flow( float sum, int count, float dt );

    float compute_velocity( float flow, int axis_length, float distance );

    /**
     * Parameters for opencv's calcOpticalFlowFarneback
    */
    const float pyr_scale = 0.5;
    const int levels      = 5;
    const int winsize     = 13;
    const int iterations  = 10;
    const int poly_n      = 5;
    const float poly_sigma  = 1.1;

};

#endif