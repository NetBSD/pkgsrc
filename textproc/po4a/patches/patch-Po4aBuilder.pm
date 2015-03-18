$NetBSD: patch-Po4aBuilder.pm,v 1.2 2015/03/18 02:25:23 mef Exp $

(1) ryoon: remove gzip at initial import
(2) mef: Add PerlIO::F_UTF8 () macro
(3) mef: to avoid --previous option is said unknown to msgmerge
    (but sounds strange)

--- Po4aBuilder.pm.orig	2013-08-22 05:11:04.000000000 +0900
+++ Po4aBuilder.pm	2015-03-18 11:10:49.000000000 +0900
@@ -8,6 +8,8 @@ use File::stat;
 
 @ISA = qw(Module::Build);
 
+sub PerlIO::F_UTF8 () { 0x00008000 } # from perliol.h
+
 sub ACTION_build {
     my $self = shift;
     $self->depends_on('code');
@@ -104,7 +106,7 @@ sub ACTION_binpo {
         my $lang = fileparse($_, qw{.po});
         unless ($self->up_to_date("po/bin/po4a.pot", $_)) {
             print "XX Sync $_: ";
-            system("msgmerge --previous $_ po/bin/po4a.pot -o $_.new") && die;
+            system("msgmerge $_ po/bin/po4a.pot -o $_.new") && die;
             # Typically all that changes was a date. I'd
             # prefer not to commit such changes, so detect
             # and ignore them.
@@ -253,8 +255,6 @@ sub ACTION_man {
         }
         $parser->parse_from_file ($file, $out);
 
-        system("gzip -9 -f $out") and die;
-        unlink "$file" || die;
     }
 
     # Install the manpages written in XML DocBook
@@ -265,9 +265,7 @@ sub ACTION_man {
         if ($file =~ m,(.*/man(.))/([^/]*)\.xml$,) {
             my ($outdir, $section, $outfile) = ($1, $2, $3);
             system("xsltproc -o $outdir/$outfile.$section --nonet http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl $file") and die;
-            system ("gzip -9 -f $outdir/$outfile.$section") and die;
         }
-        unlink "$file" || die;
     }
 }
 
