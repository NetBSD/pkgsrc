$NetBSD: patch-Po4aBuilder.pm,v 1.1 2014/12/03 07:08:36 ryoon Exp $

--- Po4aBuilder.pm.orig	2013-08-21 20:11:04.000000000 +0000
+++ Po4aBuilder.pm
@@ -253,8 +253,6 @@ sub ACTION_man {
         }
         $parser->parse_from_file ($file, $out);
 
-        system("gzip -9 -f $out") and die;
-        unlink "$file" || die;
     }
 
     # Install the manpages written in XML DocBook
@@ -265,9 +263,7 @@ sub ACTION_man {
         if ($file =~ m,(.*/man(.))/([^/]*)\.xml$,) {
             my ($outdir, $section, $outfile) = ($1, $2, $3);
             system("xsltproc -o $outdir/$outfile.$section --nonet http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl $file") and die;
-            system ("gzip -9 -f $outdir/$outfile.$section") and die;
         }
-        unlink "$file" || die;
     }
 }
 
