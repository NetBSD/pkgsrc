$NetBSD: patch-Po4aBuilder.pm,v 1.3 2020/03/05 13:19:32 schmonz Exp $

(1) ryoon: remove gzip at initial import
(2) mef: Add PerlIO::F_UTF8 () macro
(3) mef: to avoid --previous option is said unknown to msgmerge
    (but sounds strange)
(4) schmonz: avoid xsltproc attempting network fetch

--- Po4aBuilder.pm.orig	2019-10-25 10:32:20.000000000 +0000
+++ Po4aBuilder.pm
@@ -9,6 +9,8 @@ use File::stat;
 
 @ISA = qw(Module::Build);
 
+sub PerlIO::F_UTF8 () { 0x00008000 } # from perliol.h
+
 sub ACTION_build {
     my $self = shift;
     $self->depends_on('code');
@@ -81,7 +83,7 @@ sub ACTION_binpo {
         my $lang = fileparse($_, qw{.po});
         unless ($self->up_to_date("po/bin/po4a.pot", $_)) {
             print "XX Sync $_: ";
-            system("msgmerge --previous $_ po/bin/po4a.pot -o $_.new") && die;
+            system("msgmerge $_ po/bin/po4a.pot -o $_.new") && die;
             # Typically all that changes was a date. I'd
             # prefer not to commit such changes, so detect
             # and ignore them.
@@ -233,8 +235,6 @@ sub ACTION_man {
         }
         $parser->parse_from_file ($file, $out);
 
-        system("gzip -9 -f $out") and die;
-        unlink "$file" || die;
     }
 
     # Install the manpages written in XML DocBook
@@ -244,10 +244,8 @@ sub ACTION_man {
     foreach $file (@{$self->rscan_dir($manpath, qr{\.xml$})}) {
         if ($file =~ m,(.*/man(.))/([^/]*)\.xml$,) {
             my ($outdir, $section, $outfile) = ($1, $2, $3);
-            system("xsltproc -o $outdir/$outfile.$section --nonet http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl $file") and die;
-            system ("gzip -9 -f $outdir/$outfile.$section") and die;
+            system("xsltproc -o $outdir/$outfile.$section --nonet @PREFIX@/share/xsl/docbook/manpages/docbook.xsl $file") and die;
         }
-        unlink "$file" || die;
     }
 }
 
