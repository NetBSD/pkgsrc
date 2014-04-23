$NetBSD: patch-qtmultimedia_src_gsttools_qgstreamervideoinputdevicecontrol.cpp,v 1.2 2014/04/23 07:05:31 adam Exp $

--- qtmultimedia/src/gsttools/qgstreamervideoinputdevicecontrol.cpp.orig	2014-02-01 20:37:58.000000000 +0000
+++ qtmultimedia/src/gsttools/qgstreamervideoinputdevicecontrol.cpp
@@ -44,7 +44,12 @@
 #include <QtCore/QDir>
 #include <QtCore/QDebug>
 
+#ifdef __linux__
 #include <linux/types.h>
+#include <linux/videodev2.h>
+#elif defined(__NetBSD__)
+#include <sys/videoio.h>
+#endif
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/poll.h>
@@ -54,7 +59,6 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/mman.h>
-#include <linux/videodev2.h>
 
 QGstreamerVideoInputDeviceControl::QGstreamerVideoInputDeviceControl(QObject *parent)
     :QVideoDeviceSelectorControl(parent), m_source(0), m_selectedDevice(0)
