$NetBSD: patch-qtserialport_src_serialport_qserialport__unix.cpp,v 1.1 2014/02/09 17:19:14 wiedi Exp $

SunOS doesn't have cfmakeraw
--- qtserialport/src/serialport/qserialport_unix.cpp.orig	2013-12-08 17:09:55.000000000 +0000
+++ qtserialport/src/serialport/qserialport_unix.cpp
@@ -236,7 +236,15 @@ bool QSerialPortPrivate::open(QIODevice:
     }
 
     currentTermios = restoredTermios;
+#if defined(__sun)
+    currentTermios.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+    currentTermios.c_oflag &= ~OPOST;
+    currentTermios.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+    currentTermios.c_cflag &= ~(CSIZE|PARENB);
+    currentTermios.c_cflag |= CS8;
+#else
     ::cfmakeraw(&currentTermios);
+#endif
     currentTermios.c_cflag |= CLOCAL;
     currentTermios.c_cc[VTIME] = 0;
     currentTermios.c_cc[VMIN] = 0;
