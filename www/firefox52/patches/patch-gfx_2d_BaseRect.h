$NetBSD: patch-gfx_2d_BaseRect.h,v 1.1 2024/08/02 08:55:34 martin Exp $

This file uses std::numeric_limits so requires <limits> to be
included.

--- gfx/2d/BaseRect.h.orig	2017-04-11 04:13:04.000000000 +0200
+++ gfx/2d/BaseRect.h	2024-08-02 10:48:48.470377261 +0200
@@ -9,6 +9,7 @@
 #include <algorithm>
 #include <cmath>
 #include <ostream>
+#include <limits>
 
 #include "mozilla/Assertions.h"
 #include "mozilla/FloatingPoint.h"
