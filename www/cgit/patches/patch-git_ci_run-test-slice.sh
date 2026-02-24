$NetBSD: patch-git_ci_run-test-slice.sh,v 1.1 2026/02/24 21:06:53 wiz Exp $

Fix unportable test(1) operator.

--- git/ci/run-test-slice.sh.orig	2026-02-24 20:57:43.652492603 +0000
+++ git/ci/run-test-slice.sh
@@ -11,7 +11,7 @@ handle_failed_tests
 handle_failed_tests
 
 # We only have one unit test at the moment, so run it in the first slice
-if [ "$1" == "0" ] ; then
+if [ "$1" = "0" ] ; then
 	group "Run unit tests" make --quiet -C t unit-tests-test-tool
 fi
 
