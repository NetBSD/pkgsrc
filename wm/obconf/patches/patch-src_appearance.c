$NetBSD: patch-src_appearance.c,v 1.1 2026/08/17 16:37:58 ryoon Exp $

* Fix build with GCC 14. For toupper(3).

--- src/appearance.c.orig	2026-08-17 16:23:44.268786068 +0000
+++ src/appearance.c
@@ -17,6 +17,7 @@
    See the COPYING file for a copy of the GNU General Public License.
 */
 
+#include <ctype.h>
 #include "main.h"
 #include "tree.h"
 #include "preview_update.h"
