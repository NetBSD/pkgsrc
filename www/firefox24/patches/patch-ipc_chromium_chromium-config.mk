$NetBSD: patch-ipc_chromium_chromium-config.mk,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- ipc/chromium/chromium-config.mk.orig	2013-07-30 00:58:17.000000000 +0000
+++ ipc/chromium/chromium-config.mk
@@ -105,6 +105,14 @@ DEFINES += \
   $(NULL)
 
 else # } {
+ifeq ($(OS_ARCH),SunOS) # {
+
+OS_SOLARIS = 1
+DEFINES += \
+  -DOS_SOLARIS=1 \
+  $(NULL)
+
+else # } {
 
 OS_LINUX = 1
 DEFINES += \
@@ -117,4 +125,5 @@ endif # }
 endif # }
 endif # }
 endif # }
+endif # }
 
