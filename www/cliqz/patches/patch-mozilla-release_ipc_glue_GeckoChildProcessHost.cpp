$NetBSD: patch-mozilla-release_ipc_glue_GeckoChildProcessHost.cpp,v 1.1 2019/04/19 14:02:03 fox Exp $

* Support Solaris
* Fix NetBSD linking

Original patch from ryoon, imported from www/firefox

--- mozilla-release/ipc/glue/GeckoChildProcessHost.cpp.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/ipc/glue/GeckoChildProcessHost.cpp
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
