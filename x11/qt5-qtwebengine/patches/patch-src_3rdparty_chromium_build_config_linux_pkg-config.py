$NetBSD: patch-src_3rdparty_chromium_build_config_linux_pkg-config.py,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/build/config/linux/pkg-config.py.orig	2020-07-08 16:23:41.835664158 +0000
+++ src/3rdparty/chromium/build/config/linux/pkg-config.py
@@ -59,8 +59,15 @@ def SetConfigPath(options):
     print("You must specify an architecture via -a if using a sysroot.")
     sys.exit(1)
 
-  libdir = sysroot + '/usr/' + options.system_libdir + '/pkgconfig'
-  libdir += ':' + sysroot + '/usr/share/pkgconfig'
+  if "linux" in sys.platform:
+    libdir = sysroot + '/libdata/' + options.system_libdir + '/pkgconfig'
+    libdir += ':' + sysroot + '/usr/share/pkgconfig'
+  elif "netbsd" in sys.platform:
+    libdir = sysroot + '/lib/pkgconfig'
+    libdir += ':' + '/usr/lib/pkgconfig'
+  elif "freebsd" in sys.platform:
+    libdir = sysroot + '/libdata/pkgconfig'
+    libdir += ':' + '/usr/libdata/pkgconfig'
   os.environ['PKG_CONFIG_LIBDIR'] = libdir
   return libdir
 
@@ -109,7 +116,7 @@ def main():
   # If this is run on non-Linux platforms, just return nothing and indicate
   # success. This allows us to "kind of emulate" a Linux build from other
   # platforms.
-  if "linux" not in sys.platform:
+  if "linux" not in sys.platform and "bsd" not in sys.platform:
     print("[[],[],[],[],[]]")
     return 0
 
