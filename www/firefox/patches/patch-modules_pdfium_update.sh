$NetBSD: patch-modules_pdfium_update.sh,v 1.1 2017/09/30 05:34:12 ryoon Exp $

--- modules/pdfium/update.sh.orig	2017-09-14 20:15:53.000000000 +0000
+++ modules/pdfium/update.sh
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
