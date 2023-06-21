$NetBSD: patch-Po4aBuilder.pm,v 1.10 2023/06/21 19:08:06 schmonz Exp $

(1) ryoon: remove gzip at initial import.
(2) mef: Add PerlIO::F_UTF8 () macro.
(3) schmonz: Use a sufficiently capable diff.
(4) schmonz: Invoke pkgsrc's gettext-tools.
(5) schmonz: Write to the full physical null device.

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
+            system("@PREFIX@/bin/msgmerge --previous $_ po/bin/po4a.pot -o $_.new") && die;
             # Typically all that changes was a date. I'd
             # prefer not to commit such changes, so detect
             # and ignore them.
-            $diff = qx(diff -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' $_ $_.new);
+            $diff = qx(@DIFF@ -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' $_ $_.new);
             if ($diff eq "") {
                 unlink "$_.new" || die;
                 # touch it
@@ -101,7 +103,7 @@ sub ACTION_binpo {
       }
         unless ($self->up_to_date($_,"blib/po/$lang/LC_MESSAGES/po4a.mo")) {
             mkpath( File::Spec->catdir( 'blib', 'po', $lang, "LC_MESSAGES" ), 0, oct(755) );
-            system("msgfmt -o blib/po/$lang/LC_MESSAGES/po4a.mo $_") && die;
+            system("@PREFIX@/bin/msgfmt -o blib/po/$lang/LC_MESSAGES/po4a.mo $_") && die;
         }
     }
 }
@@ -222,9 +224,9 @@ sub ACTION_man {
                 $parser->{release} = $parser->{center} = "Po4a Tools";
         } else {
                 my $command;
-                $command = "msggrep -K -E -e \"Po4a Tools\" po/pod/$lang.po |";
-                $command .= "msgconv -t UTF-8 | ";
-                $command .= "msgexec /bin/sh -c '[ -n \"\$MSGEXEC_MSGID\" ] ";
+                $command = "@PREFIX@/bin/msggrep -K -E -e \"Po4a Tools\" po/pod/$lang.po |";
+                $command .= "@PREFIX@/bin/msgconv -t UTF-8 | ";
+                $command .= "@PREFIX@/bin/msgexec @SH@ -c '[ -n \"\$MSGEXEC_MSGID\" ] ";
                 $command .= "&& cat || cat > /dev/null'";
 
                 my $title = `$command 2> /dev/null`;
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
@@ -284,7 +282,7 @@ sub postats {
     foreach (sort @files) {
         $file = $_;
         my $lang = fileparse($file, qw{.po});
-        my $stat = `msgfmt -o /dev/null -c --statistics $file 2>&1`;
+        my $stat = `@PREFIX@/bin/msgfmt -o @PO4A_DEVNULL@ -c --statistics $file 2>&1`;
 	my ($trans, $fuzz, $untr) = (0,0,0);
 	if ($stat =~ /(\d+)\D+?(\d+)\D+?(\d+)/) {
 	  ($trans, $fuzz, $untr) = ($1,$2,$3);
