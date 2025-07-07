$NetBSD: patch-base_posix_unix__domain__socket__unittest.cc,v 1.3 2025/07/07 09:23:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/posix/unix_domain_socket_unittest.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ base/posix/unix_domain_socket_unittest.cc
@@ -15,6 +15,8 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#include <signal.h>
+
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/functional/bind.h"
