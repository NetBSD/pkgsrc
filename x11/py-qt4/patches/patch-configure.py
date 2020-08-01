$NetBSD: patch-configure.py,v 1.3 2020/08/01 07:18:35 tnn Exp $

--- configure.py.orig	2018-08-31 07:36:58.000000000 +0000
+++ configure.py
@@ -341,14 +341,14 @@ class ConfigurePyQt4:
         pyqt_modules.append("QtCore")
 
         check_module("QtGui", "qwidget.h", "new QWidget()")
-        check_module("QtHelp", "qhelpengine.h", "new QHelpEngine(\"foo\")")
+        check_module("QtHelp", "qhelpengine.h", "new QHelpEngine(\"foo\")", extra_libs=["QtCore"])
         check_module("QtMultimedia", "QAudioDeviceInfo",
                 "new QAudioDeviceInfo()")
         check_module("QtNetwork", "qhostaddress.h", "new QHostAddress()")
 
         # Qt v4.7 was current when we added support for QtDBus and we didn't
         # bother properly versioning its API.
-        if qt_version >= 0x040700:
+        if qt_version >= 0x040700 and os.path.isdir(os.path.join(src_dir, "dbus")):
             check_module("QtDBus", "qdbusconnection.h",
                     "QDBusConnection::systemBus()")
 
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
 
