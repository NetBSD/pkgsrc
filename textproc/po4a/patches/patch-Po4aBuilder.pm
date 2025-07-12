$NetBSD: patch-Po4aBuilder.pm,v 1.13 2025/07/12 15:34:12 adam Exp $

(1) ryoon: remove gzip at initial import.
(2) mef: Add PerlIO::F_UTF8 () macro.
(3) schmonz: Use a sufficiently capable diff.
(4) schmonz: Invoke pkgsrc's gettext-tools.
(5) schmonz: Write to the full physical null device.

--- Po4aBuilder.pm.orig	2025-07-12 13:28:07.000000000 +0000
+++ Po4aBuilder.pm
@@ -18,6 +18,8 @@ use File::stat qw(lstat stat);
 
 use IPC::Open3 qw(open3);
 
+sub PerlIO::F_UTF8 () { 0x00008000 } # from perliol.h
+
 sub ACTION_build {
     my $self = shift;
     $self->depends_on('code');
@@ -68,7 +70,7 @@ sub ACTION_binpo {
         chdir "../..";
 	
         if ( -e "po/bin/po4a.pot") {
-            my $diff = qx(diff -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' po/bin/po4a.pot po/bin/po4a.pot.new);
+            my $diff = qx(@DIFF@ -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' po/bin/po4a.pot po/bin/po4a.pot.new);
             if ( $diff eq "" ) {
                 unlink "po/bin/po4a.pot.new" or die;
                 # touch it
@@ -90,11 +92,11 @@ sub ACTION_binpo {
       if ($lang eq 'de') {
         unless ($self->up_to_date("po/bin/po4a.pot", $_)) {
             print "XX Sync $_: ";
-            system("msgmerge", "--previous", $_, "po/bin/po4a.pot", "-o", "$_.new") && die;
+            system("@PREFIX@/bin/msgmerge", "--previous", $_, "po/bin/po4a.pot", "-o", "$_.new") && die;
             # Typically all that changes was a date. I'd
             # prefer not to commit such changes, so detect
             # and ignore them.
-            my $diff = qx(diff -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' $_ $_.new);
+            my $diff = qx(@DIFF@ -q -I'#:' -I'POT-Creation-Date:' -I'PO-Revision-Date:' $_ $_.new);
             if ($diff eq "") {
                 unlink "$_.new" or die;
                 # touch it
@@ -109,7 +111,7 @@ sub ACTION_binpo {
       }
         unless ($self->up_to_date($_,"blib/po/$lang/LC_MESSAGES/po4a.mo")) {
             mkpath( File::Spec->catdir( 'blib', 'po', $lang, "LC_MESSAGES" ), 0, oct(755) );
-            system("msgfmt", "-o", "blib/po/$lang/LC_MESSAGES/po4a.mo", $_) && die;
+            system("@PREFIX@/bin/msgfmt", "-o", "blib/po/$lang/LC_MESSAGES/po4a.mo", $_) && die;
         }
     }
 }
@@ -231,9 +233,9 @@ sub ACTION_man {
             $parser->{release} = $parser->{center} = "Po4a Tools";
         } else {
             my $command;
-            $command = "msggrep -K -E -e \"Po4a Tools\" po/pod/$lang.po |";
-            $command .= "msgconv -t UTF-8 | ";
-            $command .= "msgexec /bin/sh -c '[ -n \"\$MSGEXEC_MSGID\" ] ";
+            $command = "@PREFIX@/bin/msggrep -K -E -e \"Po4a Tools\" po/pod/$lang.po |";
+            $command .= "@PREFIX@/bin/msgconv -t UTF-8 | ";
+            $command .= "@PREFIX@/bin/msgexec @SH@ -c '[ -n \"\$MSGEXEC_MSGID\" ] ";
             $command .= "&& cat || cat > /dev/null'";
 
             my $title = `$command 2> /dev/null`;
@@ -243,8 +245,6 @@ sub ACTION_man {
         }
         $parser->parse_from_file( $file, $out );
 
-        system("gzip", "-9", "-n", "-f", $out) and die;
-        unlink "$file" or die;
     }
 
     if ( $^O ne 'MSWin32' ) {
@@ -275,9 +275,7 @@ sub ACTION_man {
                     print "Convert $outdir/$outfile.$section (online docbook.xsl file). ";
                     system("xsltproc", "-o", "$outdir/$outfile.$section", "--nonet", $docbook_xsl_url, $file) and die;
                 }
-                system("gzip", "-9", "-n", "-f", "$outdir/$outfile.$section") and die;
             }
-            unlink "$file" or die;
         }
     }
 }
@@ -305,7 +303,7 @@ sub postats {
     my (@t100,@t95,@t90,@t80,@t70,@t50,@t33,@t20,@starting);
     foreach my $file (sort @files) {
         my $lang = fileparse($file, qw{.po});
-        my $stat = `msgfmt -o /dev/null -c --statistics $file 2>&1`;
+        my $stat = `@PREFIX@/bin/msgfmt -o @PO4A_DEVNULL@ -c --statistics $file 2>&1`;
 	my ($trans, $fuzz, $untr) = (0,0,0);
 	if ($stat =~ /(\d+)\D+?(\d+)\D+?(\d+)/) {
 	  ($trans, $fuzz, $untr) = ($1,$2,$3);
