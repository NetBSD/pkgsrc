$NetBSD: patch-configure.py,v 1.1 2015/01/27 06:10:15 dbj Exp $

--- configure.py.orig	2014-07-03 14:00:02.000000000 +0000
+++ configure.py
@@ -346,7 +346,7 @@ class ConfigurePyQt4:
         pyqt_modules.append("QtCore")
 
         check_module("QtGui", "qwidget.h", "new QWidget()")
-        check_module("QtHelp", "qhelpengine.h", "new QHelpEngine(\"foo\")")
+        check_module("QtHelp", "qhelpengine.h", "new QHelpEngine(\"foo\")", extra_libs=["QtCore"])
         check_module("QtMultimedia", "QAudioDeviceInfo",
                 "new QAudioDeviceInfo()")
         check_module("QtNetwork", "qhostaddress.h", "new QHostAddress()")
@@ -372,8 +372,8 @@ class ConfigurePyQt4:
         check_module("QtTest", "QtTest", "QTest::qSleep(0)")
         check_module("QtWebKit", "qwebpage.h", "new QWebPage()")
         check_module("QtXmlPatterns", "qxmlname.h", "new QXmlName()")
-        check_module("phonon", "phonon/videowidget.h",
-                "new Phonon::VideoWidget()")
+#        check_module("phonon", "phonon/videowidget.h",
+#                "new Phonon::VideoWidget()")
         check_module("QtAssistant", "qassistantclient.h",
                 "new QAssistantClient(\"foo\")", extra_lib_dirs=ass_lib_dirs,
                 extra_libs=ass_libs)
@@ -968,7 +968,7 @@ include(%s)
 
                 config_args = ducfg.get("CONFIG_ARGS", "")
 
-                if sys.platform == "darwin":
+                if False: # sys.platform == "darwin":
                     dynamic_pylib = "--enable-framework" in config_args
 
                     # It's probably a Python bug that the library name doesn't
@@ -1963,8 +1963,8 @@ def get_qt_configuration():
         else:
             exe_file = os.path.join("release", app + ".exe")
             make_target = " release"
-    elif sys.platform == "darwin":
-        exe_file = os.path.join(app + ".app", "Contents", "MacOS", app)
+#    elif sys.platform == "darwin":
+#        exe_file = os.path.join(app + ".app", "Contents", "MacOS", app)
     else:
         exe_file = os.path.join(".", app)
 
@@ -2027,11 +2027,7 @@ int main(int argc, char **argv)
 
     out << QLibraryInfo::licensee() << '\\n';
 
-#if defined(QT_SHARED) || defined(QT_DLL)
     out << "shared\\n";
-#else
-    out << "static\\n";
-#endif
 
     // Determine which features should be disabled.
 
