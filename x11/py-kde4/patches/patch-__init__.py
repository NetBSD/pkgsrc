$NetBSD: patch-__init__.py,v 1.1 2012/03/19 19:44:04 markd Exp $

deal with possible lack of DLFCN package as its only on Linux and Solaris

--- __init__.py.orig	2008-07-22 12:00:52.000000000 +1200
+++ __init__.py
@@ -1,4 +1,22 @@
-import sys,DLFCN
+import sys
+try:
+    from DLFCN import RTLD_NOW, RTLD_GLOBAL
+except ImportError:
+    RTLD_GLOBAL = -1
+    RTLD_NOW = -1
+    import os
+    osname = os.uname()[0]
+    if osname == 'Linux' or osname == 'SunOS' or osname == 'FreeBSD' or osname == 'NetBSD':
+        RTLD_GLOBAL = 0x100
+        RTLD_NOW = 0x2
+    elif osname == 'Darwin':
+        RTLD_GLOBAL = 0x8
+        RTLD_NOW = 0x2
+    del os
+except:
+    RTLD_GLOBAL = -1
+    RTLD_NOW = -1
+
 # This is needed to ensure that dynamic_cast and RTTI works inside kdelibs.
-sys.setdlopenflags(DLFCN.RTLD_NOW|DLFCN.RTLD_GLOBAL)
-     
\ No newline at end of file
+if RTLD_GLOBAL != -1 and RTLD_NOW != -1:
+    sys.setdlopenflags(RTLD_NOW|RTLD_GLOBAL)
