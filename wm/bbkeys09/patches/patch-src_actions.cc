$NetBSD: patch-src_actions.cc,v 1.1 2011/11/25 22:21:28 joerg Exp $

--- src/actions.cc.orig	2011-11-25 16:59:00.000000000 +0000
+++ src/actions.cc
@@ -24,6 +24,7 @@
 
 #include "actions.hh"
 
+#include <cstdlib>
 #include <iostream>
 #include <string>
 #include <sstream>
