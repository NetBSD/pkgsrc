$NetBSD: patch-qtmultimedia_src_plugins_gstreamer_camerabin_camerabinserviceplugin.cpp,v 1.2 2014/07/24 15:51:56 jperkin Exp $

Pull in correct includes on NetBSD and SunOS.

--- qtmultimedia/src/plugins/gstreamer/camerabin/camerabinserviceplugin.cpp.orig	2014-02-01 20:37:59.000000000 +0000
+++ qtmultimedia/src/plugins/gstreamer/camerabin/camerabinserviceplugin.cpp
@@ -50,7 +50,14 @@
 #include "camerabinservice.h"
 #include <private/qgstutils_p.h>
 
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
@@ -60,7 +67,6 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/mman.h>
-#include <linux/videodev2.h>
 #include <gst/gst.h>
 
 QT_BEGIN_NAMESPACE
