$NetBSD: patch-mozilla_modules_pdfium_update.sh,v 1.1 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/modules/pdfium/update.sh.orig	2020-02-17 23:37:59.000000000 +0000
+++ mozilla/modules/pdfium/update.sh
@@ -124,9 +124,9 @@ update_readme() {
     perl -p -i -e "s/${PREFIX} [0-9A-Fa-f]+ \(.+\)/${PREFIX} ${COMMIT} (${COMMIT_DATE})/" README_MOZILLA
 }
 
-if [ "$#" == 0 ]; then
+if [ "$#" = 0 ]; then
     COMMIT_SELECTOR="master"
-elif [ "$#" == 2 -a "$1" == "--commit" ]; then
+elif [ "$#" = 2 -a "$1" = "--commit" ]; then
     COMMIT_SELECTOR="$2"
 else
     print_help
