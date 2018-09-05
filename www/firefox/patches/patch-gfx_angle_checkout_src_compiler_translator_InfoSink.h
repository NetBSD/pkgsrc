$NetBSD: patch-gfx_angle_checkout_src_compiler_translator_InfoSink.h,v 1.1 2018/09/05 15:29:58 ryoon Exp $

* isinf/isnan in make.h is defined as macro. Use non-macro version
  to fix build.

--- gfx/angle/checkout/src/compiler/translator/InfoSink.h.orig	2018-08-30 16:44:19.000000000 +0000
+++ gfx/angle/checkout/src/compiler/translator/InfoSink.h
@@ -7,7 +7,7 @@
 #ifndef COMPILER_TRANSLATOR_INFOSINK_H_
 #define COMPILER_TRANSLATOR_INFOSINK_H_
 
-#include <math.h>
+#include <cmath>
 #include <stdlib.h>
 #include "compiler/translator/Common.h"
 #include "compiler/translator/Severity.h"
