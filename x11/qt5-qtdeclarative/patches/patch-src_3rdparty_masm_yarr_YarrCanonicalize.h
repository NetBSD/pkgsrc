$NetBSD: patch-src_3rdparty_masm_yarr_YarrCanonicalize.h,v 1.1 2018/12/18 09:57:59 adam Exp $

Void conflict with textproc/icu:
src/3rdparty/masm/stubs/wtf/unicode/utypes.h only includes Unicode.h.

--- src/3rdparty/masm/yarr/YarrCanonicalize.h.orig	2018-12-16 16:58:47.000000000 +0000
+++ src/3rdparty/masm/yarr/YarrCanonicalize.h
@@ -26,7 +26,7 @@
 #pragma once
 
 #include <stdint.h>
-#include <unicode/utypes.h>
+#include "unicode/Unicode.h"
 
 namespace JSC { namespace Yarr {
 
