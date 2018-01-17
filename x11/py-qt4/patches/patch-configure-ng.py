$NetBSD: patch-configure-ng.py,v 1.1 2018/01/17 19:18:47 markd Exp $

--- configure-ng.py.orig	2017-06-30 08:44:36.000000000 +0000
+++ configure-ng.py
@@ -591,11 +591,7 @@ int main(int argc, char **argv)
 
     out << QLibraryInfo::licensee() << '\\n';
 
-#if defined(QT_SHARED) || defined(QT_DLL)
     out << "shared\\n";
-#else
-    out << "static\\n";
-#endif
 
     // Determine which features should be disabled.
 
@@ -1290,9 +1286,9 @@ def check_modules(target_config, verbose
     check_module(target_config, verbose, 'QtXmlPatterns', 'qxmlname.h',
             'new QXmlName()')
 
-    if target_config.qt_version < 0x050000:
-        check_module(target_config, verbose, 'phonon', 'phonon/videowidget.h',
-                'new Phonon::VideoWidget()')
+#    if target_config.qt_version < 0x050000:
+#        check_module(target_config, verbose, 'phonon', 'phonon/videowidget.h',
+#                'new Phonon::VideoWidget()')
 
     if target_config.qt_version < 0x040700:
         check_module(target_config, verbose, 'QtAssistant',
