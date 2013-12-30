$NetBSD: patch-qtmultimedia_src_plugins_gstreamer_audiodecoder_qgstreameraudiodecoderserviceplugin.cpp,v 1.1 2013/12/30 06:37:11 ryoon Exp $

--- qtmultimedia/src/plugins/gstreamer/audiodecoder/qgstreameraudiodecoderserviceplugin.cpp.orig	2013-12-20 09:09:03.000000000 +0000
+++ qtmultimedia/src/plugins/gstreamer/audiodecoder/qgstreameraudiodecoderserviceplugin.cpp
@@ -49,7 +49,12 @@
 #include <QtCore/QDir>
 #include <QtCore/QDebug>
 
+#if defined(__linux__)
 #include <linux/types.h>
+#include <linux/videodev2.h>
+#elif defined(__NetBSD__)
+#include <sys/videoio.h>
+#endif
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/poll.h>
@@ -59,7 +64,6 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/mman.h>
-#include <linux/videodev2.h>
 #include <gst/gst.h>
 
 // #define QT_SUPPORTEDMIMETYPES_DEBUG
