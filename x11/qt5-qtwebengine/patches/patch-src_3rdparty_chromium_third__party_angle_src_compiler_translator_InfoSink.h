$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_compiler_translator_InfoSink.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/angle/src/compiler/translator/InfoSink.h.orig	2020-07-15 19:01:32.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/compiler/translator/InfoSink.h
@@ -7,7 +7,7 @@
 #ifndef COMPILER_TRANSLATOR_INFOSINK_H_
 #define COMPILER_TRANSLATOR_INFOSINK_H_
 
-#include <math.h>
+#include <cmath>
 #include <stdlib.h>
 #include "compiler/translator/Common.h"
 #include "compiler/translator/Severity.h"
