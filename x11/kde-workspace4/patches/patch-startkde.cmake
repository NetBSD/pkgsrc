$NetBSD: patch-startkde.cmake,v 1.3 2013/11/07 13:35:56 markd Exp $

--- startkde.cmake.orig	2013-03-01 06:32:24.000000000 +0000
+++ startkde.cmake
@@ -29,6 +29,12 @@ else
   qdbus=qdbus
 fi
 
+qtbindir=@QTDIR@/bin
+case $PATH in
+  $qtbindir|$qtbindir:*|*:$qtbindir|*:$qtbindir:*) ;;
+  *) PATH=$qtbindir:$PATH; export PATH;;
+esac
+
 # Check if a KDE session already is running and whether it's possible to connect to X
 kcheckrunning
 kcheckrunning_result=$?
@@ -189,11 +195,11 @@ usr_fdir=$HOME/.fonts
 
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
