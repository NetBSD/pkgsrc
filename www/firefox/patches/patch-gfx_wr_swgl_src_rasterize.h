$NetBSD: patch-gfx_wr_swgl_src_rasterize.h,v 1.1 2026/08/24 12:51:47 ryoon Exp $

--- gfx/wr/swgl/src/rasterize.h.orig	2026-08-12 13:09:04.000000000 +0000
+++ gfx/wr/swgl/src/rasterize.h
@@ -32,6 +32,8 @@
 // a given row, the row will be converted to the flattened representation to
 // support it, after which it will only ever revert back to runs if the depth
 // buffer is cleared.
+#include <cmath>
+using std::isfinite;
 
 // The largest 24-bit depth value supported.
 constexpr uint32_t MAX_DEPTH_VALUE = 0xFFFFFF;
