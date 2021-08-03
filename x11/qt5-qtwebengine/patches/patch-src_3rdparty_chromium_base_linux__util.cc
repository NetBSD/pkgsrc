$NetBSD: patch-src_3rdparty_chromium_base_linux__util.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/linux_util.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/linux_util.cc
@@ -19,6 +19,7 @@
 #include "base/files/dir_reader_posix.h"
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
+#include "base/logging.h"
 #include "base/no_destructor.h"
 #include "base/strings/safe_sprintf.h"
 #include "base/strings/string_number_conversions.h"
