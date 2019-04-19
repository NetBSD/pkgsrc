$NetBSD: patch-magic__build__and__package.sh,v 1.1 2019/04/19 14:02:03 fox Exp $

Disable build and packaging of tests.

--- magic_build_and_package.sh.orig	2019-04-10 11:18:54.578708528 +0000
+++ magic_build_and_package.sh
@@ -43,8 +43,8 @@ fi
 echo '***** Building *****'
 ./mach build
 
-echo '***** Building tests *****'
-./mach build package-tests
+#echo '***** Building tests *****'
+#./mach build package-tests
 
 echo '***** Packaging *****'
 ./mach package
