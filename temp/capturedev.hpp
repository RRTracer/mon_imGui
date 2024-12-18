/*
 * Fichier d'en tête capturedev.hpp pour le projet miniDart
 * Auteur : Eric Bachard  / lundi 3 octobre 2016, 14:35:03 (UTC+0200)
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __CAPTUREDEV__HPP
#define __CAPTUREDEV__HPP

#include <SDL2/SDL.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <cstdlib>
#include <list>
#include <queue>

class CaptureDev
{
  public:
    CaptureDev();
    virtual ~CaptureDev();
    bool                Init(int);
    cv::VideoCapture    maVideoCap;
    cv::Mat             USBFrame;
    void                getFrame();
    bool                IsCaptureOpened();
    bool                IsCapturePaused();
    void                setCaptureFPS(int);
    void                setDevNumber(int);
    int                 getDevNumber(void);
    void                set_delay(int);
    int                 get_delay(void);
    double              getCaptureFPS();
    double              getWidth();
    double              getHeight();
    cv::Size            getFrameSize();
    void                initializeFrameSize();
    void                setFrameSize(double, double);
    void                setFourCC(unsigned int);
    void                setConvertRGB(bool);
    void                Update();
    void                Render();
    void                Close();
    bool                bFirstFrameSuccess(void);
    bool                bLostWebcam(void);
    bool                canReadFrame(int, unsigned int, unsigned int);

    //std::vector<uint8_t> image_buffer;

  private:
    int                 maDevNumber;
    double              mfWidth;
    double              mfHeight;
    double              mfCaptureFPS;
    cv::Size            maFrameSize;
    int                 md_delay;
    //short int           mdStackSize;
    bool                mb_opened;
    bool                mb_paused;
    long                mdPos_msec;
    long                mdFramePos;
    unsigned int        mdFourcc;
};

#endif /* __CAPTUREDEV__HPP */

