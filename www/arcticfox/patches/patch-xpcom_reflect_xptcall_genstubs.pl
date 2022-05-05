$NetBSD: patch-xpcom_reflect_xptcall_genstubs.pl,v 1.2 2022/05/05 14:07:38 nia Exp $

Bring NetBSD in line with other BSDs. 
Not sure abut the impact, but there is no reason to single it out

--- xpcom/reflect/xptcall/genstubs.pl.orig	2022-02-03 04:20:33.000000000 +0000
+++ xpcom/reflect/xptcall/genstubs.pl
@@ -44,7 +44,7 @@ print OUTFILE "*  0 is QueryInterface\n"
 print OUTFILE "*  1 is AddRef\n";
 print OUTFILE "*  2 is Release\n";
 print OUTFILE "*/\n";
-print OUTFILE "#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__))\n";
+print OUTFILE "#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__) && !defined(__NetBSD__))\n";
 for($i = 0; $i < $entry_count; $i++) {
     print OUTFILE "NS_IMETHOD Stub",$i+3,"();\n";
 }
