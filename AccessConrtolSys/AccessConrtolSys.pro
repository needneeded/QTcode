QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += D:\software\opencv\opencv-4.8.0\build\install\include

# 配置opencv的库路径。注意：如果qt选择Debugger模式运行，那么库文件选择opencv_world480d。否则选择opencv_world480
LIBS += -LD:\software\opencv\opencv-4.8.0\build\lib\Release \
        -lopencv_core480 \
        -lopencv_imgproc480 \
        -lopencv_highgui480 \
        -lopencv_imgcodecs480 \
        -lopencv_objdetect480 \
        -lopencv_video480 \
        -lopencv_videoio480

# # 添加Dlib头文件路径
INCLUDEPATH += D:\software\dlib\build\install\include

# 链接具体的dlib库文件
LIBS += -LD:\software\dlib\build\install\lib \
        -lD:\software\dlib\build\install\lib\dlib19.24.99_release_64bit_msvc1941

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dlibfacelivenessdetector.cpp \
    faceenter.cpp \
    facerecognize.cpp \
    faceutils.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    TConversion.hpp \
    dlibfacelivenessdetector.h \
    faceenter.h \
    facerecognize.h \
    faceutils.h \
    mainwindow.h

FORMS += \
    faceenter.ui \
    facerecognize.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
