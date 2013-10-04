$NetBSD: patch-booster_lib_system_src_posix__error.cpp,v 1.1 2013/10/04 18:27:48 joerg Exp $

--- booster/lib/system/src/posix_error.cpp.orig	2013-10-02 08:26:29.475306600 +0000
+++ booster/lib/system/src/posix_error.cpp
@@ -5,6 +5,7 @@
 //  accompanying file LICENSE_1_0.txt or copy at
 //  http://www.boost.org/LICENSE_1_0.txt)
 //
+#define _GNU_SOURCE
 #define BOOSTER_SOURCE
 #include <booster/config.h>
 #include <booster/system_error.h>
