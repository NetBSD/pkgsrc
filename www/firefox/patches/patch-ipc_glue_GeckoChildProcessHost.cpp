$NetBSD: patch-ipc_glue_GeckoChildProcessHost.cpp,v 1.13 2017/08/10 14:46:15 ryoon Exp $

* Support Solaris
* Fix NetBSD linking

--- ipc/glue/GeckoChildProcessHost.cpp.orig	2017-07-31 16:20:47.000000000 +0000
+++ ipc/glue/GeckoChildProcessHost.cpp
@@ -4,7 +4,13 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#if defined(__NetBSD__)
+_Pragma("GCC visibility push(default)")
+#endif
 #include "GeckoChildProcessHost.h"
+#if defined(__NetBSD__)
+_Pragma("GCC visibility pop")
+#endif
 
 #include "base/command_line.h"
 #include "base/string_util.h"
