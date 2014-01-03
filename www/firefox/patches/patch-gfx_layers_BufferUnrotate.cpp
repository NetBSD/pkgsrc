$NetBSD: patch-gfx_layers_BufferUnrotate.cpp,v 1.1 2014/01/03 14:30:28 martin Exp $

Addd missing include of string.h for memcpy().


--- gfx/layers/BufferUnrotate.cpp.orig	2013-12-05 17:07:31.000000000 +0100
+++ gfx/layers/BufferUnrotate.cpp	2014-01-03 15:03:25.000000000 +0100
@@ -8,6 +8,7 @@
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 void BufferUnrotate(uint8_t* aBuffer, int aByteWidth, int aHeight,
                     int aByteStride, int aXBoundary, int aYBoundary)
