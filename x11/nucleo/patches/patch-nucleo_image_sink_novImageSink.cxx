$NetBSD: patch-nucleo_image_sink_novImageSink.cxx,v 1.1 2012/10/09 08:56:13 marino Exp $

Fix this error on gcc4.7:
novImageSink.cxx:60:13: error: 'close' was not declared in this scope

--- nucleo/image/sink/novImageSink.cxx.orig	2008-06-05 12:52:33.000000000 +0000
+++ nucleo/image/sink/novImageSink.cxx
@@ -20,6 +20,7 @@
 #include <sys/uio.h>
 
 #include <stdexcept>
+#include <unistd.h>
 
 namespace nucleo {
 
