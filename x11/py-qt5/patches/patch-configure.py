$NetBSD: patch-configure.py,v 1.3.4.1 2016/05/07 19:02:18 bsiegert Exp $

On Darwin, do not expect application bundle.
Adapt for pkgsrc change to make qmake create libtool files.

--- configure.py.orig	2015-10-25 11:42:16.000000000 +0000
+++ configure.py
@@ -1932,10 +1932,7 @@ def run_make(target_config, verbose, exe
         make = 'make'
         makefile_target = ''
 
-        if target_config.py_platform == 'darwin':
-            platform_exe = os.path.join(exe + '.app', 'Contents', 'MacOS', exe)
-        else:
-            platform_exe = os.path.join('.', exe)
+        platform_exe = os.path.join('.', exe)
 
     remove_file(platform_exe)
 
@@ -2441,8 +2438,10 @@ win32 {
     target.files = %s%s.pyd
     LIBS += %s
 } else {
-    PY_MODULE = %s.so
-    target.files = %s.so
+    PY_MODULE = %s.la
+    target.files = %s.la
+    LIBS += -Wl,-rpath,@X11LIB@
+    LIBS += -Wl,-rpath,@PREFIX@/lib/pulseaudio
 }
 ''' % (target_name, debug_suffix, target_name, debug_suffix, link, target_name, target_name)
 
@@ -2517,9 +2514,6 @@ win32 {
             # common case where the PyQt configuration reflects the Qt
             # configuration.
             fwks = []
-            for m in ('QtPrintSupport', 'QtDBus', 'QtWidgets'):
-                if m in target_config.pyqt_modules:
-                    fwks.append('-framework ' + m)
 
             if len(fwks) != 0:
                 extra_lflags = 'QMAKE_LFLAGS += "%s"\n        ' % ' '.join(fwks)
@@ -2532,7 +2526,6 @@ win32 {
 }
 macx {
     QMAKE_LFLAGS += "-undefined dynamic_lookup"
-    QMAKE_LFLAGS += "-install_name $$absolute_path($$PY_MODULE, $$target.path)"
 
     greaterThan(QT_MINOR_VERSION, 4) {
         %sQMAKE_RPATHDIR += $$[QT_INSTALL_LIBS]
