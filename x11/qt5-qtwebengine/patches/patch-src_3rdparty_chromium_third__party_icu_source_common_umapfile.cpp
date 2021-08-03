$NetBSD: patch-src_3rdparty_chromium_third__party_icu_source_common_umapfile.cpp,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/icu/source/common/umapfile.cpp.orig	2020-07-15 19:01:35.000000000 +0000
+++ src/3rdparty/chromium/third_party/icu/source/common/umapfile.cpp
@@ -19,7 +19,7 @@
  *----------------------------------------------------------------------------*/
 /* Defines _XOPEN_SOURCE for access to POSIX functions.
  * Must be before any other #includes. */
-#include "uposixdefs.h"
+//#include "uposixdefs.h"
 
 #include "unicode/putil.h"
 #include "unicode/ustring.h"
