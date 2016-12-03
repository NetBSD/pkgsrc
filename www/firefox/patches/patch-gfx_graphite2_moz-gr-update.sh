$NetBSD: patch-gfx_graphite2_moz-gr-update.sh,v 1.3 2016/12/03 09:58:26 ryoon Exp $

--- gfx/graphite2/moz-gr-update.sh.orig	2016-07-25 20:22:05.000000000 +0000
+++ gfx/graphite2/moz-gr-update.sh
@@ -1,6 +1,7 @@
 #!/bin/bash
 
 # Script used to update the Graphite2 library in the mozilla source tree
+# and bump version for --with-system-graphite2
 
 # This script lives in gfx/graphite2, along with the library source,
 # but must be run from the top level of the mozilla-central tree.
@@ -37,12 +38,16 @@ echo "See" $0 "for update procedure." >>
 #find gfx/graphite2/ -name "*.cpp" -exec perl -p -i -e "s/<cstdio>/<stdio.h>/;s/Windows.h/windows.h/;" {} \;
 #find gfx/graphite2/ -name "*.h" -exec perl -p -i -e "s/<cstdio>/<stdio.h>/;s/Windows.h/windows.h/;" {} \;
 
+# chase version for --with-system-graphite2
+perl -p -i -e "s/[0-9]+\,[0-9]+\,[0-9]+/$RELEASE/ and tr/./,/ \
+  if /GR2_VERSION_REQUIRE/" old-configure.in
+
 # summarize what's been touched
 echo Updated to $RELEASE.
 echo Here is what changed in the gfx/graphite2 directory:
 echo
 
-hg stat gfx/graphite2
+hg stat old-configure.in gfx/graphite2
 
 echo
 echo If gfx/graphite2/src/files.mk has changed, please make corresponding
