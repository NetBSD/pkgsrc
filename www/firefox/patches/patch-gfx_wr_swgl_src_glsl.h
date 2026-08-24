$NetBSD: patch-gfx_wr_swgl_src_glsl.h,v 1.1 2026/08/24 12:51:47 ryoon Exp $

--- gfx/wr/swgl/src/glsl.h.orig	2026-08-12 13:09:03.000000000 +0000
+++ gfx/wr/swgl/src/glsl.h
@@ -2,6 +2,9 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#include <cmath>
+using std::fpclassify;
+
 #define SI ALWAYS_INLINE static
 
 #include "vector_type.h"
