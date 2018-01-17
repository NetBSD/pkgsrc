$NetBSD: patch-configure.py,v 1.2 2018/01/17 19:18:47 markd Exp $

--- configure.py.orig	2017-06-30 08:44:36.000000000 +0000
+++ configure.py
@@ -341,7 +341,7 @@ class ConfigurePyQt4:
         pyqt_modules.append("QtCore")
 
         check_module("QtGui", "qwidget.h", "new QWidget()")
-        check_module("QtHelp", "qhelpengine.h", "new QHelpEngine(\"foo\")")
+        check_module("QtHelp", "qhelpengine.h", "new QHelpEngine(\"foo\")", extra_libs=["QtCore"])
         check_module("QtMultimedia", "QAudioDeviceInfo",
                 "new QAudioDeviceInfo()")
         check_module("QtNetwork", "qhostaddress.h", "new QHostAddress()")
@@ -367,8 +367,8 @@ class ConfigurePyQt4:
         check_module("QtWebKit", "qwebpage.h", "new QWebPage()")
         check_module("QtXml", "qdom.h", "new QDomDocument()")
         check_module("QtXmlPatterns", "qxmlname.h", "new QXmlName()")
-        check_module("phonon", "phonon/videowidget.h",
-                "new Phonon::VideoWidget()")
+#        check_module("phonon", "phonon/videowidget.h",
+#                "new Phonon::VideoWidget()")
         check_module("QtAssistant", "qassistantclient.h",
                 "new QAssistantClient(\"foo\")", extra_lib_dirs=ass_lib_dirs,
                 extra_libs=ass_libs)
@@ -963,7 +963,7 @@ include(%s)
 
                 config_args = ducfg.get("CONFIG_ARGS", "")
 
-                if sys.platform == "darwin":
+                if False: # sys.platform == "darwin":
                     dynamic_pylib = "--enable-framework" in config_args
 
                     # It's probably a Python bug that the library name doesn't
@@ -1950,8 +1950,8 @@ def get_qt_configuration():
         else:
             exe_file = os.path.join("release", app + ".exe")
             make_target = " release"
-    elif sys.platform == "darwin":
-        exe_file = os.path.join(app + ".app", "Contents", "MacOS", app)
+#    elif sys.platform == "darwin":
+#        exe_file = os.path.join(app + ".app", "Contents", "MacOS", app)
     else:
         exe_file = os.path.join(".", app)
 
@@ -2014,11 +2014,7 @@ int main(int argc, char **argv)
 
     out << QLibraryInfo::licensee() << '\\n';
 
-#if defined(QT_SHARED) || defined(QT_DLL)
     out << "shared\\n";
-#else
-    out << "static\\n";
-#endif
 
     // Determine which features should be disabled.
 
