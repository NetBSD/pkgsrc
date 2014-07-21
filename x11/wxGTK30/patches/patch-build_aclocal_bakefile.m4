$NetBSD: patch-build_aclocal_bakefile.m4,v 1.1 2014/07/21 06:53:24 dbj Exp $
Fix shell script portability

--- build/aclocal/bakefile.m4.orig	2014-06-14 21:48:48.000000000 +0000
+++ build/aclocal/bakefile.m4
@@ -371,7 +371,7 @@ AC_DEFUN([AC_BAKEFILE_SHARED_LD],
             SHARED_LD_CXX="\${CXX} -dynamiclib -single_module -headerpad_max_install_names -o"
         fi
 
-        if test "x$GCC" == "xyes"; then
+        if test "x$GCC" = "xyes"; then
             PIC_FLAG="-dynamic -fPIC"
         fi
         if test "x$XLCC" = "xyes"; then
