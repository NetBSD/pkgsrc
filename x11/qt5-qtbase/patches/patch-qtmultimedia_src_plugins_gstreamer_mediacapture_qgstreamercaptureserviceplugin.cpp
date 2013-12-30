$NetBSD: patch-qtmultimedia_src_plugins_gstreamer_mediacapture_qgstreamercaptureserviceplugin.cpp,v 1.1 2013/12/30 06:37:11 ryoon Exp $

--- qtmultimedia/src/plugins/gstreamer/mediacapture/qgstreamercaptureserviceplugin.cpp.orig	2013-12-20 09:17:00.000000000 +0000
+++ qtmultimedia/src/plugins/gstreamer/mediacapture/qgstreamercaptureserviceplugin.cpp
@@ -51,7 +51,12 @@
 #include "qgstreamercaptureservice.h"
 #include <private/qgstutils_p.h>
 
+#ifdef __linux__
 #include <linux/types.h>
+#include <linux/videodev2.h>
+#elif defined(__NetBSD__)
+#include <sys/videoio.h>
+#endif
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/poll.h>
@@ -61,7 +66,6 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/mman.h>
-#include <linux/videodev2.h>
 #include <gst/gst.h>
 
 QMediaService* QGstreamerCaptureServicePlugin::create(const QString &key)
