$NetBSD: patch-mozilla-release_gfx_angle_checkout_src_compiler_translator_InfoSink.h,v 1.1 2019/04/19 14:02:03 fox Exp $

* isinf/isnan in make.h is defined as macro. Use non-macro version
  to fix build.

Original patch from ryoon, imported from www/firefox

--- mozilla-release/gfx/angle/checkout/src/compiler/translator/InfoSink.h.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/gfx/angle/checkout/src/compiler/translator/InfoSink.h
@@ -7,7 +7,7 @@
 #ifndef COMPILER_TRANSLATOR_INFOSINK_H_
 #define COMPILER_TRANSLATOR_INFOSINK_H_
 
-#include <math.h>
+#include <cmath>
 #include <stdlib.h>
 #include "compiler/translator/Common.h"
 #include "compiler/translator/Severity.h"
