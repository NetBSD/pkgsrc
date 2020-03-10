$NetBSD: patch-Source_ThirdParty_ANGLE_adjust-angle-include-paths.sh,v 1.2 2020/03/10 18:14:04 leot Exp $

Avoid unportable `==' test(1) operator.

--- Source/ThirdParty/ANGLE/adjust-angle-include-paths.sh.orig	2020-02-04 10:24:05.000000000 +0000
+++ Source/ThirdParty/ANGLE/adjust-angle-include-paths.sh
@@ -19,7 +19,7 @@
 # that they refer to each other. This avoids modifying the ANGLE
 # sources, and allows WebCore to more easily call ANGLE APIs directly.
 
-if [ "$DEPLOYMENT_LOCATION" == "YES" ] ; then
+if [ "$DEPLOYMENT_LOCATION" = "YES" ] ; then
     # Apple-internal build.
     output_dir=${DSTROOT}${PUBLIC_HEADERS_FOLDER_PATH}
 else
@@ -27,7 +27,7 @@ else
     output_dir=${BUILT_PRODUCTS_DIR}${PUBLIC_HEADERS_FOLDER_PATH}
 fi
 
-if [ $(uname) == "Linux" ]; then
+if [ $(uname) = "Linux" ]; then
     inplace_opt=(-i)
 else
     inplace_opt=(-i "")
