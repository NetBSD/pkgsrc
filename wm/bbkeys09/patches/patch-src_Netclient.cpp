$NetBSD: patch-src_Netclient.cpp,v 1.1 2011/11/25 22:21:28 joerg Exp $

--- src/Netclient.cpp.orig	2011-11-25 17:00:35.000000000 +0000
+++ src/Netclient.cpp
@@ -21,9 +21,9 @@
 // DEALINGS IN THE SOFTWARE.
 
 // E_O_H_VR
+#include <cstring>
 
 // Methods, ideas, implementations taken from Openbox's XAtom class *sigh*
-
 #include "Netclient.h"
 
 Netclient::Netclient (const bt::Display &display)
