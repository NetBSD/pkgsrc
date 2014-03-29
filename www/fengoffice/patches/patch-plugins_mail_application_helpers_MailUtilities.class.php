$NetBSD: patch-plugins_mail_application_helpers_MailUtilities.class.php,v 1.6 2014/03/29 14:17:06 taca Exp $

* Fix variable mistakes to prevent garbled characters.  Still needs to
  fix essential problem when a header contains multiple encoded strings
  with diffreent charset.

--- plugins/mail/application/helpers/MailUtilities.class.php.orig	2014-02-17 10:24:14.000000000 +0000
+++ plugins/mail/application/helpers/MailUtilities.class.php
@@ -287,7 +287,7 @@ class MailUtilities {
 			if ($from_name == ''){
 				$from_name = $from;
 			} else if (strtoupper($encoding) =='KOI8-R' || strtoupper($encoding) =='CP866' || $from_encoding != 'UTF-8' || !$enc_conv->isUtf8RegExp($from_name)){ //KOI8-R and CP866 are Russian encodings which PHP does not detect
-				$utf8_from = $enc_conv->convert($encoding, 'UTF-8', $from_name);
+                $utf8_from = $enc_conv->convert($from_encoding, 'UTF-8', $from_name);
 	
 				if ($enc_conv->hasError()) {
 					$utf8_from = utf8_encode($from_name);
