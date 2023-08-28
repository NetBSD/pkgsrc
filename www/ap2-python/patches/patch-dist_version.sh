$NetBSD: patch-dist_version.sh,v 1.2 2023/08/28 09:47:46 gdt Exp $

Don't depend on 'git'.

--- dist/version.sh.orig	2023-08-18 17:28:08.000000000 +0000
+++ dist/version.sh
@@ -6,6 +6,8 @@ MAJ=`awk '/MP_VERSION_MAJOR/ {print $3}'
 MIN=`awk '/MP_VERSION_MINOR/ {print $3}' $MPV_PATH`
 PCH=`awk '/MP_VERSION_PATCH/ {print $3}' $MPV_PATH`
 
+if false; then
+
 # if git exists in path
 if type git >/dev/null 2>&1; then
     # and we are in a checkout
@@ -18,4 +20,6 @@ if type git >/dev/null 2>&1; then
     fi
 fi
 
+fi
+
 echo $MAJ.$MIN.$PCH$GIT
