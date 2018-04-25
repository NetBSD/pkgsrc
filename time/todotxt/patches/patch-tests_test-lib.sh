$NetBSD: patch-tests_test-lib.sh,v 1.1 2018/04/25 15:23:55 leot Exp $

Instead of unconditionally use today date try to use `date -r'. According a
quick skim of NetBSD, FreeBSD and OpenBSD date(1) man pages, all of them should
support that.

--- tests/test-lib.sh.orig	2018-04-25 14:30:34.714587570 +0000
+++ tests/test-lib.sh
@@ -535,7 +535,14 @@ test_init_todo () {
 		;;
 		*)
 			echo "WARNING: Current date executable not recognized"
-			echo "So today date will be used, expect false negative tests..."
+			echo "'date -r' will be used, expect false negative tests"
+			echo "if date(1) on your system does not support -r"
+			echo "option!"
+			cat > bin/date <<-EOF
+			#!/bin/sh
+			exec "$TODO_TEST_REAL_DATE" -r \$TODO_TEST_TIME \$@
+			EOF
+			chmod 755 bin/date
 		;;
 	esac
 
