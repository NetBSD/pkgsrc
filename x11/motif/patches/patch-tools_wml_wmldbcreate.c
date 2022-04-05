$NetBSD: patch-tools_wml_wmldbcreate.c,v 1.1 2022/04/05 10:00:21 riastradh Exp $

wmldbcreate is a tool that runs at build-time.  Rather than link
against libXm, which may have been cross-compiled, just include the one
set of string definitions it needs anyway.

--- tools/wml/wmldbcreate.c.orig	2017-08-17 00:38:43.000000000 +0000
+++ tools/wml/wmldbcreate.c
@@ -84,6 +84,8 @@ static char rcsid[] = "$TOG: wmldbcreate
 #include "UilSymChCl.h" /* from WML */
 #include "UilSymChTa.h" /* from WML */
 
+#include "../../lib/Xm/XmStrDefs.c"
+
 void emit_globals();
 void emit_header(_db_header_ptr header);
 void emit_chars(int	    table_id);
