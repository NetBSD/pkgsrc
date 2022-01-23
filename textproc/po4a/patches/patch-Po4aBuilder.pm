$NetBSD: patch-Po4aBuilder.pm,v 1.6 2022/01/23 10:04:55 schmonz Exp $

(1) ryoon: remove gzip at initial import
(2) mef: Add PerlIO::F_UTF8 () macro
(3) mef: to avoid --previous option is said unknown to msgmerge
    (but sounds strange)

--- Po4aBuilder.pm.orig	2022-01-02 00:10:18.000000000 +0000
+++ Po4aBuilder.pm
@@ -9,6 +9,8 @@ use File::stat;
 
 @ISA = qw(Module::Build);
 
+sub PerlIO::F_UTF8 () { 0x00008000 } # from perliol.h
+
 sub ACTION_build {
     my $self = shift;
     $self->depends_on('code');
@@ -82,7 +84,7 @@ sub ACTION_binpo {
       if (0) {
         unless ($self->up_to_date("po/bin/po4a.pot", $_)) {
             print "XX Sync $_: ";
-            system("msgmerge --previous $_ po/bin/po4a.pot -o $_.new") && die;
+            system("msgmerge $_ po/bin/po4a.pot -o $_.new") && die;
             # Typically all that changes was a date. I'd
             # prefer not to commit such changes, so detect
             # and ignore them.
@@ -234,8 +236,6 @@ sub ACTION_man {
         }
         $parser->parse_from_file ($file, $out);
 
-        system("gzip -9 -f $out") and die;
-        unlink "$file" || die;
     }
 
     # Install the manpages written in XML DocBook
@@ -252,9 +252,7 @@ sub ACTION_man {
 		print "Convert $outdir/$outfile.$section (online docbook.xsl file). ";
 		system("xsltproc -o $outdir/$outfile.$section --nonet http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl $file") and die;
 	    }
-            system ("gzip -9 -f $outdir/$outfile.$section") and die;
         }
-        unlink "$file" || die;
     }
 }
 
