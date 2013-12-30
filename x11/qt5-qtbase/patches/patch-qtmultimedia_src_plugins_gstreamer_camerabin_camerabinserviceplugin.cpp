$NetBSD: patch-qtmultimedia_src_plugins_gstreamer_camerabin_camerabinserviceplugin.cpp,v 1.1 2013/12/30 06:37:11 ryoon Exp $

--- qtmultimedia/src/plugins/gstreamer/camerabin/camerabinserviceplugin.cpp.orig	2013-12-20 09:28:04.000000000 +0000
+++ qtmultimedia/src/plugins/gstreamer/camerabin/camerabinserviceplugin.cpp
@@ -50,7 +50,12 @@
 #include "camerabinservice.h"
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
@@ -60,7 +65,6 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/mman.h>
-#include <linux/videodev2.h>
 #include <gst/gst.h>
 
 QT_BEGIN_NAMESPACE
