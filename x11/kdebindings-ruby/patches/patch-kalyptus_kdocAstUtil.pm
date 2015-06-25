$NetBSD: patch-kalyptus_kdocAstUtil.pm,v 1.1 2015/06/25 07:44:46 joerg Exp $

--- kalyptus/kdocAstUtil.pm.orig	2005-09-10 08:16:39.000000000 +0000
+++ kalyptus/kdocAstUtil.pm
@@ -674,8 +674,7 @@ sub dumpAst
 		dumpAst( $kid );
 	}
 
-	print "\t" x $depth, "Documentation nodes:\n" if defined 
-		@{ $node->{Doc}->{ "Text" }};
+	print "\t" x $depth, "Documentation nodes:\n" if (@{ $node->{Doc}->{ "Text" }});
 
 	foreach $kid ( @{ $node->{Doc}->{ "Text" }} ) {
 		dumpAst( $kid );
