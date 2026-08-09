$NetBSD: patch-base_posix_unix__domain__socket__unittest.cc,v 1.24 2026/08/09 06:31:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/posix/unix_domain_socket_unittest.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ base/posix/unix_domain_socket_unittest.cc
@@ -10,6 +10,8 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#include <signal.h>
+
 #include "base/compiler_specific.h"
 #include "base/files/scoped_file.h"
 #include "base/functional/bind.h"
