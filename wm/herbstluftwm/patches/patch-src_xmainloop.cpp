$NetBSD: patch-src_xmainloop.cpp,v 1.1 2024/10/10 17:08:25 nia Exp $

illumos needs string.h for FD_ZERO.

error: 'memset' was not declared in this scope
  194 |         FD_ZERO(&in_fds);

--- src/xmainloop.cpp.orig	2024-10-10 17:01:28.487070309 +0000
+++ src/xmainloop.cpp
@@ -7,6 +7,7 @@
 #include <sys/wait.h>
 #include <iostream>
 #include <memory>
+#include <cstring>
 
 #include "client.h"
 #include "clientmanager.h"
