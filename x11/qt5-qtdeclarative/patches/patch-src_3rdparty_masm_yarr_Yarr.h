$NetBSD: patch-src_3rdparty_masm_yarr_Yarr.h,v 1.1 2021/07/09 22:52:54 markd Exp $

Add missing limits include to fix build with GCC 11

--- src/3rdparty/masm/yarr/Yarr.h.orig	2020-10-27 08:02:12.000000000 +0000
+++ src/3rdparty/masm/yarr/Yarr.h
@@ -28,6 +28,7 @@
 #pragma once
 
 #include <limits.h>
+#include <limits>
 #include "YarrErrorCode.h"
 
 namespace JSC { namespace Yarr {
