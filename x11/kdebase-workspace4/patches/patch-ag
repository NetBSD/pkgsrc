$NetBSD: patch-ag,v 1.2 2011/01/23 07:55:16 markd Exp $

--- startkde.cmake.orig	2007-11-29 02:29:24.000000000 +1300
+++ startkde.cmake
@@ -38,6 +38,12 @@ if [ -n "$bindir" ]; then
   esac
 fi
 
+qtbindir=@QTDIR@/bin
+case $PATH in
+  $qtbindir|$qtbindir:*|*:$qtbindir|*:$qtbindir:*) ;;
+  *) PATH=$qtbindir:$PATH; export PATH;;
+esac
+
 # Boot sequence:
 #
 # kdeinit is used to fork off processes which improves memory usage
@@ -219,11 +225,11 @@ usr_fdir=$HOME/.fonts
 
 if test -n "$KDEDIRS"; then
   kdedirs_first=`echo "$KDEDIRS"|sed -e 's/:.*//'`
-  sys_odir=$kdedirs_first/share/fonts/override
-  sys_fdir=$kdedirs_first/share/fonts
+  sys_odir=$kdedirs_first/share/kde/fonts/override
+  sys_fdir=$kdedirs_first/share/kde/fonts
 else
-  sys_odir=$KDEDIR/share/fonts/override
-  sys_fdir=$KDEDIR/share/fonts
+  sys_odir=$KDEDIR/share/kde/fonts/override
+  sys_fdir=$KDEDIR/share/kde/fonts
 fi
 
 # We run mkfontdir on the user's font dirs (if we have permission) to pick
