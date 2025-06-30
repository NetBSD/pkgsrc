$NetBSD: patch-include_mpdf_vendor_paragonie_random__compat_build-phar.sh,v 1.1 2025/06/30 14:34:15 hauke Exp $

Un-bash

--- include/mpdf/vendor/paragonie/random_compat/build-phar.sh.orig	2025-06-23 11:45:58.911126445 +0000
+++ include/mpdf/vendor/paragonie/random_compat/build-phar.sh
@@ -1,5 +1,5 @@
 #!/usr/bin/env bash
 
-basedir=$( dirname $( readlink -f ${BASH_SOURCE[0]} ) )
+basedir=$( dirname $( readlink -f ${0} ) )
 
 php -dphar.readonly=0 "$basedir/other/build_phar.php" $*
\ No newline at end of file
