$NetBSD: patch-Source_ThirdParty_ANGLE_src_common_mathutil.h,v 1.1 2024/08/17 10:58:39 tnn Exp $

error: 'uint32_t' does not name a type
  575 | inline uint32_t RotL(uint32_t x, int8_t r)

--- Source/ThirdParty/ANGLE/src/common/mathutil.h.orig	2024-08-17 11:56:20.701400148 +0000
+++ Source/ThirdParty/ANGLE/src/common/mathutil.h
@@ -16,6 +16,7 @@
 #include <algorithm>
 #include <string.h>
 #include <stdlib.h>
+#include <cstdint>
 
 namespace gl
 {
