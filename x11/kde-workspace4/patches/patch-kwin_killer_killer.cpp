$NetBSD: patch-kwin_killer_killer.cpp,v 1.1 2013/06/22 22:39:10 jperkin Exp $

Consolidate pid_t types on SunOS.

--- kwin/killer/killer.cpp.orig	2013-05-03 04:36:45.632117897 +0000
+++ kwin/killer/killer.cpp
@@ -87,7 +87,11 @@ int main(int argc, char* argv[])
             if (::kill(pid, SIGKILL) && errno == EPERM) {
                 KAuth::Action killer("org.kde.ksysguard.processlisthelper.sendsignal");
                 killer.setHelperID("org.kde.ksysguard.processlisthelper");
+#ifdef __sun
+                killer.addArgument("pid0", (int)pid);
+#else
                 killer.addArgument("pid0", pid);
+#endif
                 killer.addArgument("pidcount", 1);
                 killer.addArgument("signal", SIGKILL);
                 if (killer.isValid()) {
