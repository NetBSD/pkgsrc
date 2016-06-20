$NetBSD: patch-src_commands_CmdEdit.cpp,v 1.1 2016/06/20 20:30:42 kamil Exp $

Include <errno.h> for errno.

--- src/commands/CmdEdit.cpp.orig	2015-10-21 20:25:42.000000000 +0000
+++ src/commands/CmdEdit.cpp
@@ -36,6 +36,7 @@
 #include <Filter.h>
 #include <Nibbler.h>
 #include <i18n.h>
+#include <errno.h>
 #include <text.h>
 #include <util.h>
 #include <i18n.h>
