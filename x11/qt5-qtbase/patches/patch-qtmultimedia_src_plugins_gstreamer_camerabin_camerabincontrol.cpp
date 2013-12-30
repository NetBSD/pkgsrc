$NetBSD: patch-qtmultimedia_src_plugins_gstreamer_camerabin_camerabincontrol.cpp,v 1.1 2013/12/30 06:37:11 ryoon Exp $

--- qtmultimedia/src/plugins/gstreamer/camerabin/camerabincontrol.cpp.orig	2013-12-20 09:31:52.000000000 +0000
+++ qtmultimedia/src/plugins/gstreamer/camerabin/camerabincontrol.cpp
@@ -50,7 +50,12 @@
 #include <QtCore/qfile.h>
 #include <QtCore/qmetaobject.h>
 
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
 
 QT_BEGIN_NAMESPACE
 
