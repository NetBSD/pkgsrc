$NetBSD: patch-gfx_angle_checkout_src_compiler_translator_InfoSink.h,v 1.1.4.1 2022/02/20 10:20:21 bsiegert Exp $

* isinf/isnan in make.h is defined as macro. Use non-macro version
  to fix build.

--- gfx/angle/checkout/src/compiler/translator/InfoSink.h.orig	2022-01-06 00:52:35.000000000 +0000
+++ gfx/angle/checkout/src/compiler/translator/InfoSink.h
@@ -7,7 +7,7 @@
 #ifndef COMPILER_TRANSLATOR_INFOSINK_H_
 #define COMPILER_TRANSLATOR_INFOSINK_H_
 
-#include <math.h>
+#include <cmath>
 #include <stdlib.h>
 #include "GLSLANG/ShaderLang.h"
 #include "compiler/translator/Common.h"
