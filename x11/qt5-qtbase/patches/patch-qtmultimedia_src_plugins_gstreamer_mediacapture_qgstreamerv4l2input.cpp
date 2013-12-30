$NetBSD: patch-qtmultimedia_src_plugins_gstreamer_mediacapture_qgstreamerv4l2input.cpp,v 1.1 2013/12/30 06:37:11 ryoon Exp $

NetBSD doesn't have support for v4l2_frmsizeenum and related logic.
Should be fixed properly.

--- qtmultimedia/src/plugins/gstreamer/mediacapture/qgstreamerv4l2input.cpp.orig	2013-12-20 09:12:19.000000000 +0000
+++ qtmultimedia/src/plugins/gstreamer/mediacapture/qgstreamerv4l2input.cpp
@@ -44,7 +44,12 @@
 #include <QtCore/qdebug.h>
 #include <QtCore/qfile.h>
 
+#if defined(__linux__)
+#include <linux/videodev2.h>
 #include <linux/types.h>
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
 
 QT_BEGIN_NAMESPACE
 static inline uint qHash(const QSize& key) { return uint(key.width()*256+key.height()); }
@@ -154,7 +158,7 @@ void QGstreamerV4L2Input::updateSupporte
 
 
     //get the list of resolutions:
-
+#if !defined(__NetBSD__)
     foreach (quint32 format, supportedFormats) {
         struct v4l2_frmsizeenum formatSize;
         memset(&formatSize, 0, sizeof(formatSize));
@@ -256,6 +260,7 @@ void QGstreamerV4L2Input::updateSupporte
             m_ratesByResolution[s].unite(frameRates.toSet());
         }
     }
+#endif
 
     f.close();
 
