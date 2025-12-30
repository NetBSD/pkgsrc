$NetBSD: patch-src_common_Configuration.h,v 1.1 2025/12/30 04:00:09 gutteridge Exp $

Fix hardcoded absolute paths.

--- src/common/Configuration.h.orig	2024-02-26 10:23:03.000000000 +0000
+++ src/common/Configuration.h
@@ -47,7 +47,7 @@ namespace SDDM {
                                                                                                    "NOTE: Currently ignored if autologin is enabled."));
         Entry(InputMethod,         QString,     QStringLiteral("qtvirtualkeyboard"),                   _S("Input method module"));
         Entry(Namespaces,          QStringList, QStringList(),                                  _S("Comma-separated list of Linux namespaces for user session to enter"));
-        Entry(GreeterEnvironment,  QStringList, QStringList(),                                  _S("Comma-separated list of environment variables to be set"));
+        Entry(GreeterEnvironment,  QStringList, {_S("PATH=@PREFIX@/bin:@X11BASE@/bin:/usr/bin:/bin")},        _S("Comma-separated list of environment variables to be set"));
         //  Name   Entries (but it's a regular class again)
         Section(Theme,
             Entry(ThemeDir,            QString,     _S(DATA_INSTALL_DIR "/themes"),             _S("Theme directory path"));
@@ -65,10 +65,10 @@ namespace SDDM {
 
         // TODO: Not absolutely sure if everything belongs here. Xsessions, VT and probably some more seem universal
         Section(X11,
-            Entry(ServerPath,          QString,     _S("/usr/bin/X"),                           _S("Path to X server binary"));
+            Entry(ServerPath,          QString,     _S("@X11BASE@/bin/X"),                      _S("Path to X server binary"));
             Entry(ServerArguments,     QString,     _S("-nolisten tcp"),                        _S("Arguments passed to the X server invocation"));
-            Entry(XephyrPath,          QString,     _S("/usr/bin/Xephyr"),                      _S("Path to Xephyr binary"));
-            Entry(SessionDir,          QStringList, {_S("/usr/local/share/xsessions"),
+            Entry(XephyrPath,          QString,     _S("@PREFIX@/bin/Xephyr"),                  _S("Path to Xephyr binary"));
+            Entry(SessionDir,          QStringList, {_S("@PREFIX@/share/xsessions"),
                                                      _S("/usr/share/xsessions")},               _S("Comma-separated list of directories containing available X sessions"));
             Entry(SessionCommand,      QString,     _S(SESSION_COMMAND),                        _S("Path to a script to execute when starting the desktop session"));
             Entry(SessionLogFile,      QString,     _S(".local/share/sddm/xorg-session.log"),   _S("Path to the user session log file"));
@@ -79,7 +79,7 @@ namespace SDDM {
 
         Section(Wayland,
             Entry(CompositorCommand,   QString,     _S("weston --shell=kiosk"),                 _S("Path of the Wayland compositor to execute when starting the greeter"));
-            Entry(SessionDir,          QStringList, {_S("/usr/local/share/wayland-sessions"),
+            Entry(SessionDir,          QStringList, {_S("@PREFIX@/share/wayland-sessions"),
                                                      _S("/usr/share/wayland-sessions")},        _S("Comma-separated list of directories containing available Wayland sessions"));
             Entry(SessionCommand,      QString,     _S(WAYLAND_SESSION_COMMAND),                _S("Path to a script to execute when starting the desktop session"));
             Entry(SessionLogFile,      QString,     _S(".local/share/sddm/wayland-session.log"),_S("Path to the user session log file"));
@@ -87,7 +87,7 @@ namespace SDDM {
         );
 
         Section(Users,
-            Entry(DefaultPath,         QString,     _S("/usr/local/bin:/usr/bin:/bin"),         _S("Default $PATH for logged in users"));
+            Entry(DefaultPath,         QString,     _S("@PREFIX@/bin:@X11BASE@/bin:/usr/bin:/bin"),         _S("Default $PATH for logged in users"));
             Entry(MinimumUid,          int,         UID_MIN,                                    _S("Minimum user id for displayed users"));
             Entry(MaximumUid,          int,         UID_MAX,                                    _S("Maximum user id for displayed users"));
             Entry(HideUsers,           QStringList, QStringList(),                              _S("Comma-separated list of users that should not be listed"));
