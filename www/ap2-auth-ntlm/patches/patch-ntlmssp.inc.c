$NetBSD: patch-ntlmssp.inc.c,v 1.1.1.1 2008/10/17 19:24:10 sborrill Exp $
--- ntlmssp.inc.c.orig	2004-02-19 15:21:06.000000000 +0000
+++ ntlmssp.inc.c	2008-10-17 19:33:51.000000000 +0100
@@ -1,3 +1,4 @@
+#include "httpd/httpd.h"
 /*
  * $Id: patch-ntlmssp.inc.c,v 1.1.1.1 2008/10/17 19:24:10 sborrill Exp $
  *
