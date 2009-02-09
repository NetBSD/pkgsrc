$NetBSD: patch-ntlmssp.inc.c,v 1.2 2009/02/09 18:26:46 joerg Exp $

--- ntlmssp.inc.c.orig	2004-02-19 15:21:06.000000000 +0000
+++ ntlmssp.inc.c	2008-10-17 19:33:51.000000000 +0100
@@ -1,1 +1,2 @@
+#include "httpd/httpd.h"
 /*
