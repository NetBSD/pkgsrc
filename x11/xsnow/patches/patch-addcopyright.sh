$NetBSD: patch-addcopyright.sh,v 1.1 2021/03/20 13:24:39 gdt Exp $

Work around upstream non-conforming sed expression.

\todo File upstream.

--- addcopyright.sh.orig	2021-01-11 12:22:11.000000000 +0000
+++ addcopyright.sh
@@ -57,7 +57,7 @@ while [ "$1" ] ; do
    # Notice that sed requires a newline after the filename of the 'r' command
    sed -i "/^\s*#-#/d" "$f"
    sed -i "/$txt/{r $crfile
-   :a;n;ba}" "$f"
+}" "$f"
    n=`expr $n + 1`
 done
 echo "$n files copyrighted"
