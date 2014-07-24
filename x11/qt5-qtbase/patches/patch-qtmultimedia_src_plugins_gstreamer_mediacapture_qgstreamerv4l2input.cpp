$NetBSD: patch-qtmultimedia_src_plugins_gstreamer_mediacapture_qgstreamerv4l2input.cpp,v 1.2 2014/07/24 15:51:56 jperkin Exp $

NetBSD and SunOS don't have support for v4l2_frmsizeenum and related logic.
Should be fixed properly.

Pull in correct includes on NetBSD and SunOS.

--- qtmultimedia/src/plugins/gstreamer/mediacapture/qgstreamerv4l2input.cpp.orig	2014-02-01 20:37:59.000000000 +0000
+++ qtmultimedia/src/plugins/gstreamer/mediacapture/qgstreamerv4l2input.cpp
@@ -44,7 +44,14 @@
 #include <QtCore/qdebug.h>
 #include <QtCore/qfile.h>
 
+#if defined(__linux__)
+#include <linux/videodev2.h>
 #include <linux/types.h>
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
 
 QT_BEGIN_NAMESPACE
 static inline uint qHash(const QSize& key) { return uint(key.width()*256+key.height()); }
@@ -154,7 +160,7 @@ void QGstreamerV4L2Input::updateSupporte
 
 
     //get the list of resolutions:
-
+#if !defined(__NetBSD__) && !defined(__sun)
     foreach (quint32 format, supportedFormats) {
         struct v4l2_frmsizeenum formatSize;
         memset(&formatSize, 0, sizeof(formatSize));
@@ -256,6 +262,7 @@ void QGstreamerV4L2Input::updateSupporte
             m_ratesByResolution[s].unite(frameRates.toSet());
         }
     }
+#endif
 
     f.close();
 
