$NetBSD: patch-src_helper_UserSession.cpp,v 1.1 2025/12/30 04:00:09 gutteridge Exp $

Setting up user context on NetBSD systems.

--- src/helper/UserSession.cpp.orig	2024-02-26 10:23:03.000000000 +0000
+++ src/helper/UserSession.cpp
@@ -39,7 +39,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sched.h>
-#ifdef Q_OS_FREEBSD
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 #include <login_cap.h>
 #endif
 
@@ -275,7 +275,7 @@ namespace SDDM {
             exit(Auth::HELPER_OTHER_ERROR);
         }
 
-#if defined(Q_OS_FREEBSD)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
         // execve() uses the environment prepared in Backend::openSession(),
         // therefore environment variables which are set here are ignored.
         if (setusercontext(NULL, &pw, pw.pw_uid, LOGIN_SETALL) != 0) {
@@ -341,7 +341,7 @@ namespace SDDM {
             qCritical() << "setuid(" << pw.pw_uid << ") failed for user: " << username;
             exit(Auth::HELPER_OTHER_ERROR);
         }
-#endif /* Q_OS_FREEBSD */
+#endif /* defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) */
         if (chdir(pw.pw_dir) != 0) {
             qCritical() << "chdir(" << pw.pw_dir << ") failed for user: " << username;
             qCritical() << "verify directory exist and has sufficient permissions";
