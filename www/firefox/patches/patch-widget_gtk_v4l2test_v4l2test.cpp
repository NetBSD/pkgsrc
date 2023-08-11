$NetBSD: patch-widget_gtk_v4l2test_v4l2test.cpp,v 1.1 2023/08/11 14:00:03 tnn Exp $

Add NetBSD support.

--- widget/gtk/v4l2test/v4l2test.cpp.orig	2023-07-27 18:36:17.000000000 +0000
+++ widget/gtk/v4l2test/v4l2test.cpp
@@ -9,7 +9,11 @@
 #include <cstdlib>
 #include <errno.h>
 #include <fcntl.h>
+#if defined(__NetBSD__)
+#include <sys/videoio.h>
+#else
 #include <linux/videodev2.h>
+#endif
 #include <sys/ioctl.h>
 #include <unistd.h>
 #include <string.h>
