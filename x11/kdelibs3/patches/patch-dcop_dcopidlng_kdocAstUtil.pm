$NetBSD: patch-dcop_dcopidlng_kdocAstUtil.pm,v 1.1 2015/06/15 09:24:31 joerg Exp $

--- dcop/dcopidlng/kdocAstUtil.pm.orig	2015-06-13 17:55:21.000000000 +0000
+++ dcop/dcopidlng/kdocAstUtil.pm
@@ -438,8 +438,7 @@ sub dumpAst
 		dumpAst( $kid );
 	}
 
-	print "\t" x $depth, "Documentation nodes:\n" if defined 
-		@{ $node->{Doc}->{ "Text" }};
+	print "\t" x $depth, "Documentation nodes:\n" if (@{ $node->{Doc}->{ "Text" }});
 
 	foreach $kid ( @{ $node->{Doc}->{ "Text" }} ) {
 		dumpAst( $kid );
