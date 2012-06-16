$NetBSD: patch-ConfigureChecks.cmake,v 1.1 2012/06/16 04:45:40 markd Exp $

NetBSD loginx() complains if ut_type not set before calling

--- ConfigureChecks.cmake.orig	2012-06-06 20:54:04.000000000 +0000
+++ ConfigureChecks.cmake
@@ -163,6 +163,7 @@ if (UNIX)
     endif (HAVE_UTMPX)
     if (login_in_libc OR login_in_libutil)
       set(HAVE_LOGIN 1)
+      check_struct_member("struct ${utmp}" "ut_type" "${utmp}.h" HAVE_STRUCT_UTMP_UT_TYPE)
     else (login_in_libc OR login_in_libutil)
       set(HAVE_LOGIN)
       check_struct_member("struct ${utmp}" "ut_type" "${utmp}.h" HAVE_STRUCT_UTMP_UT_TYPE)
