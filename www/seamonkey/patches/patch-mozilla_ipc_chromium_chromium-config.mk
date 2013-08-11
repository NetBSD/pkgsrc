$NetBSD: patch-mozilla_ipc_chromium_chromium-config.mk,v 1.9 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/ipc/chromium/chromium-config.mk.orig	2013-08-04 03:05:29.000000000 +0000
+++ mozilla/ipc/chromium/chromium-config.mk
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
 
