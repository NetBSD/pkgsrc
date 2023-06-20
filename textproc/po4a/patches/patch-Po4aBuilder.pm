$NetBSD: patch-Po4aBuilder.pm,v 1.9 2023/06/20 15:30:12 schmonz Exp $

(1) ryoon: remove gzip at initial import
(2) mef: Add PerlIO::F_UTF8 () macro
(3) mef: to avoid --previous option is said unknown to msgmerge
    (but sounds strange)
(4) schmonz: Use a sufficiently capable diff

--- Po4aBuilder.pm.orig	2023-01-01 00:30:43.000000000 +0000
+++ Po4aBuilder.pm
@@ -9,6 +9,8 @@ use File::stat;
 
 @ISA = qw(Module::Build);
 
+sub PerlIO::F_UTF8 () { 0x00008000 } # from perliol.h
+
 sub ACTION_build {
     my $self = shift;
     $self->depends_on('code');
@@ -60,7 +62,7 @@ sub ACTION_binpo {
         chdir "../..";
 	
         if ( -e "po/bin/po4a.pot") {
-            $diff = qx(diff -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' po/bin/po4a.pot po/bin/po4a.pot.new);
+            $diff = qx(@DIFF@ -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' po/bin/po4a.pot po/bin/po4a.pot.new);
             if ( $diff eq "" ) {
                 unlink "po/bin/po4a.pot.new" || die;
                 # touch it
@@ -82,11 +84,11 @@ sub ACTION_binpo {
       if (0) {
         unless ($self->up_to_date("po/bin/po4a.pot", $_)) {
             print "XX Sync $_: ";
-            system("msgmerge --previous $_ po/bin/po4a.pot -o $_.new") && die;
+            system("msgmerge $_ po/bin/po4a.pot -o $_.new") && die;
             # Typically all that changes was a date. I'd
             # prefer not to commit such changes, so detect
             # and ignore them.
-            $diff = qx(diff -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' $_ $_.new);
+            $diff = qx(@DIFF@ -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' $_ $_.new);
             if ($diff eq "") {
                 unlink "$_.new" || die;
                 # touch it
@@ -234,8 +236,6 @@ sub ACTION_man {
         }
         $parser->parse_from_file ($file, $out);
 
-        system("gzip -9 -n -f $out") and die;
-        unlink "$file" || die;
     }
 
     if ($^O ne 'MSWin32') {
@@ -253,9 +253,7 @@ sub ACTION_man {
             print "Convert $outdir/$outfile.$section (online docbook.xsl file). ";
             system("xsltproc -o $outdir/$outfile.$section --nonet http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl $file") and die;
             }
-                system ("gzip -9 -n -f $outdir/$outfile.$section") and die;
             }
-            unlink "$file" || die;
         }
     }
 }
