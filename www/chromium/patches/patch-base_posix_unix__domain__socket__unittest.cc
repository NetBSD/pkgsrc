$NetBSD: patch-base_posix_unix__domain__socket__unittest.cc,v 1.17 2026/04/10 17:31:46 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/posix/unix_domain_socket_unittest.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ base/posix/unix_domain_socket_unittest.cc
@@ -10,6 +10,8 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#include <signal.h>
+
 #include "base/compiler_specific.h"
 #include "base/files/scoped_file.h"
 #include "base/functional/bind.h"
