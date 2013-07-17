$NetBSD: patch-ipc_chromium_chromium-config.mk,v 1.1 2013/07/17 11:00:13 jperkin Exp $

--- ipc/chromium/chromium-config.mk.orig	2013-05-11 19:19:32.000000000 +0000
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
@@ -114,6 +122,7 @@ DEFINES += \
 endif # }
 endif # }
 endif # }
+endif # }
 endif # }
 endif # }
 endif # }
