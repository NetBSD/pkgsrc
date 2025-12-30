$NetBSD: patch-src_helper_Backend.cpp,v 1.1 2025/12/30 04:00:09 gutteridge Exp $

Add environment variables from /etc/login.conf on NetBSD systems.

--- src/helper/Backend.cpp.orig	2024-02-26 10:23:03.000000000 +0000
+++ src/helper/Backend.cpp
@@ -29,7 +29,7 @@
 
 #include <pwd.h>
 
-#if defined(Q_OS_FREEBSD)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 #include <sys/types.h>
 #include <login_cap.h>
 #endif
@@ -68,7 +68,7 @@ namespace SDDM {
             env.insert(QStringLiteral("SHELL"), QString::fromLocal8Bit(pw->pw_shell));
             env.insert(QStringLiteral("USER"), QString::fromLocal8Bit(pw->pw_name));
             env.insert(QStringLiteral("LOGNAME"), QString::fromLocal8Bit(pw->pw_name));
-#if defined(Q_OS_FREEBSD)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
         /* get additional environment variables via setclassenvironment();
             this needs to be done here instead of in UserSession::setupChildProcess
             as the environment for execve() is prepared here
@@ -82,6 +82,7 @@ namespace SDDM {
             QProcessEnvironment::systemEnvironment().clear();
             QString savedLang = env.value(QStringLiteral("LANG"));
 
+#if defined(Q_OS_FREEBSD)
             // setclassenvironment() is the implementation inside setusercontext()
             // so use lowest-level function there
             setclassenvironment(lc, pw, 1);     /* path variables */
@@ -92,7 +93,13 @@ namespace SDDM {
                 setclassenvironment(lc, pw, 0);
                 login_close(lc);
             }
-
+#elif defined(Q_OS_NETBSD)
+            // NetBSD does not have setclassenvironment() function, so 
+            // setusercontext() is used to set environment variables.
+            setusercontext(lc, pw, pw->pw_uid, LOGIN_SETPATH);
+            setusercontext(lc, pw, pw->pw_uid, LOGIN_SETENV);
+            login_close(lc);
+#endif
             // copy all environment variables that are now set
             env.insert(QProcessEnvironment::systemEnvironment());
             // for sddm itself, we don't want to set LANG from capabilities.
