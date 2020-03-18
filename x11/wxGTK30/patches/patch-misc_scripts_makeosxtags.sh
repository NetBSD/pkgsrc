$NetBSD: patch-misc_scripts_makeosxtags.sh,v 1.2 2020/03/18 14:11:37 gdt Exp $

Remediate bashism.

Not yet filed uptream.

--- misc/scripts/makeosxtags.sh.orig	2018-03-07 16:55:38.000000000 +0000
+++ misc/scripts/makeosxtags.sh
@@ -3,7 +3,7 @@
 create_tags osx
 
 osx_port=${1-cocoa}
-if [[ $osx_port = carbon ]]; then
+if [ "$osx_port" = carbon ]; then
     ext=cpp
 else
     ext=mm
