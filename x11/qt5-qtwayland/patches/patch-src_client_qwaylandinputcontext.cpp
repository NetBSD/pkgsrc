$NetBSD: patch-src_client_qwaylandinputcontext.cpp,v 1.1 2022/06/04 06:15:21 adam Exp $

Fix for undefined LC_CTYPE.

--- src/client/qwaylandinputcontext.cpp.orig	2022-06-02 18:27:18.286669600 +0000
+++ src/client/qwaylandinputcontext.cpp
@@ -37,6 +37,7 @@
 **
 ****************************************************************************/
 
+#include <clocale>
 
 #include "qwaylandinputcontext_p.h"
 
