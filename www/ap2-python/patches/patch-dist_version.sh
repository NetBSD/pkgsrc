$NetBSD: patch-dist_version.sh,v 1.1 2014/02/17 17:20:28 adam Exp $

Don't depend on 'git'.

--- dist/version.sh.orig	2014-02-17 13:35:44.000000000 +0000
+++ dist/version.sh
@@ -5,6 +5,5 @@ MPV_PATH="`dirname $0`/../src/include/mp
 MAJ=`awk '/MP_VERSION_MAJOR/ {print $3}' $MPV_PATH`
 MIN=`awk '/MP_VERSION_MINOR/ {print $3}' $MPV_PATH`
 PCH=`awk '/MP_VERSION_PATCH/ {print $3}' $MPV_PATH`
-GIT=`git describe --always`
 
-echo $MAJ.$MIN.$PCH-$GIT
+echo $MAJ.$MIN.$PCH
