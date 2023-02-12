$NetBSD: patch-lib_DtMmdb_btree__berkeley_snprintf.c,v 1.1 2023/02/12 16:34:15 vins Exp $

Avoid conflicting types for snprintf().

--- lib/DtMmdb/btree_berkeley/snprintf.c.orig	2022-10-01 17:18:27.000000000 +0000
+++ lib/DtMmdb/btree_berkeley/snprintf.c
@@ -21,12 +21,10 @@
  * Floor, Boston, MA 02110-1301 USA
  */
 /* $XConsortium: snprintf.c /main/3 1996/06/11 17:14:27 cde-hal $ */
-#include <sys/types.h>
 #include "cdefs.h"
 
 #include <compat.h>
 #include <string.h>
-#include <stdio.h>
 
 #ifdef __STDC__
 #include <stdarg.h>
