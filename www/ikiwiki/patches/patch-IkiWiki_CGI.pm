$NetBSD: patch-IkiWiki_CGI.pm,v 1.1 2014/09/13 00:08:22 schmonz Exp $

Cherry-pick feb21eb from upstream git to avoid Unicode being decoded
twice in CGI forms under Perl 5.20 (with bundled Encode.pm 2.53).

--- IkiWiki/CGI.pm.orig	2014-07-02 19:45:57.000000000 +0000
+++ IkiWiki/CGI.pm
@@ -110,11 +110,23 @@ sub decode_cgi_utf8 ($) {
 	}
 }
 
+sub safe_decode_utf8 ($) {
+    my $octets = shift;
+    # call decode_utf8 on >= 5.20 only if it's not already decoded,
+    # otherwise it balks, on < 5.20, always call it
+    if ($] < 5.02 || !Encode::is_utf8($octets)) {
+        return decode_utf8($octets);
+    }
+    else {
+        return $octets;
+    }
+}
+
 sub decode_form_utf8 ($) {
 	if ($] >= 5.01) {
 		my $form = shift;
 		foreach my $f ($form->field) {
-			my @value=map { decode_utf8($_) } $form->field($f);
+			my @value=map { safe_decode_utf8($_) } $form->field($f);
 			$form->field(name  => $f,
 			             value => \@value,
 		                     force => 1,
