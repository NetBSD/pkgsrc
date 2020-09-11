$NetBSD: patch-Source_ThirdParty_ANGLE_adjust-angle-include-paths.sh,v 1.3 2020/09/11 14:47:35 leot Exp $

Avoid unportable `==' test(1) operator.

--- Source/ThirdParty/ANGLE/adjust-angle-include-paths.sh.orig	2020-08-12 09:17:53.000000000 +0000
+++ Source/ThirdParty/ANGLE/adjust-angle-include-paths.sh
@@ -19,7 +19,7 @@
 # that they refer to each other. This avoids modifying the ANGLE
 # sources, and allows WebCore to more easily call ANGLE APIs directly.
 
-if [ "$DEPLOYMENT_LOCATION" == "YES" ] ; then
+if [ "$DEPLOYMENT_LOCATION" = "YES" ] ; then
     # Apple-internal build.
     output_dir=${DSTROOT}${PUBLIC_HEADERS_FOLDER_PATH}
 else
