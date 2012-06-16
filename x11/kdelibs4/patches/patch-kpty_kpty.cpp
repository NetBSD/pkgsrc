$NetBSD: patch-kpty_kpty.cpp,v 1.1 2012/06/16 04:45:40 markd Exp $

NetBSD loginx() complains if ut_type not set before calling

--- kpty/kpty.cpp.orig	2012-06-06 20:49:52.000000000 +0000
+++ kpty/kpty.cpp
@@ -543,6 +543,9 @@ void KPty::login(const char *user, const
     l_struct.ut_time = time(0);
 # endif
 
+# ifdef HAVE_STRUCT_UTMP_UT_TYPE
+    l_struct.ut_type = USER_PROCESS;
+# endif
 # ifdef HAVE_LOGIN
 #  ifdef HAVE_LOGINX
     ::loginx(&l_struct);
@@ -550,9 +553,6 @@ void KPty::login(const char *user, const
     ::login(&l_struct);
 #  endif
 # else
-#  ifdef HAVE_STRUCT_UTMP_UT_TYPE
-    l_struct.ut_type = USER_PROCESS;
-#  endif
 #  ifdef HAVE_STRUCT_UTMP_UT_PID
     l_struct.ut_pid = getpid();
 #   ifdef HAVE_STRUCT_UTMP_UT_SESSION
