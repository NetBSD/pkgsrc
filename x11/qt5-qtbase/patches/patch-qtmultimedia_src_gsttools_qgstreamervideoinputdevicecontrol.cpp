$NetBSD: patch-qtmultimedia_src_gsttools_qgstreamervideoinputdevicecontrol.cpp,v 1.3 2014/07/24 15:51:56 jperkin Exp $

Pull in correct includes on NetBSD and SunOS.

--- qtmultimedia/src/gsttools/qgstreamervideoinputdevicecontrol.cpp.orig	2014-02-01 20:37:58.000000000 +0000
+++ qtmultimedia/src/gsttools/qgstreamervideoinputdevicecontrol.cpp
@@ -44,7 +44,14 @@
 #include <QtCore/QDir>
 #include <QtCore/QDebug>
 
+#ifdef __linux__
 #include <linux/types.h>
+#include <linux/videodev2.h>
+#elif defined(__NetBSD__)
+#include <sys/videoio.h>
+#elif defined(__sun)
+#include <sys/videodev2.h>
+#endif
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/poll.h>
@@ -54,7 +61,6 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/mman.h>
-#include <linux/videodev2.h>
 
 QGstreamerVideoInputDeviceControl::QGstreamerVideoInputDeviceControl(QObject *parent)
     :QVideoDeviceSelectorControl(parent), m_source(0), m_selectedDevice(0)
