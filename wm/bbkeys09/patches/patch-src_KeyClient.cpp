$NetBSD: patch-src_KeyClient.cpp,v 1.2 2015/11/17 15:59:13 he Exp $

Include strings.h too.
Initialize all pointers.

--- src/KeyClient.cpp.orig	2008-12-22 01:52:35.000000000 +0000
+++ src/KeyClient.cpp
@@ -46,6 +46,7 @@ extern "C" {
 
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <strings.h>
 
 }
 
@@ -104,6 +105,10 @@ KeyClient::KeyClient (int argc, char **a
   _netclient = new Netclient(this->display());
   _active = _clients.end();
 
+  // Initialize uninitialized pointers to NULL
+  _keybindings = NULL;
+  config_check_timer = NULL;
+
   initialize();
 }
 
