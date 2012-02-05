$NetBSD: patch-wwwroot_cgi-bin_awredir.pl,v 1.1 2012/02/05 23:58:07 minskim Exp $

Security fix for http://secunia.com/advisories/46160/

--- wwwroot/cgi-bin/awredir.pl.orig	2009-01-03 10:42:04.000000000 +0000
+++ wwwroot/cgi-bin/awredir.pl
@@ -73,6 +73,27 @@ sub DecodeEncodedString {
 	return $stringtodecode;
 }
 
+#------------------------------------------------------------------------------
+# Function:     Clean a string of HTML tags to avoid 'Cross Site Scripting attacks'
+#               and clean | char.
+# Parameters:   stringtoclean
+# Input:        None
+# Output:       None
+# Return:		cleanedstring
+#------------------------------------------------------------------------------
+sub CleanXSS {
+	my $stringtoclean = shift;
+
+	# To avoid html tags and javascript
+	$stringtoclean =~ s/</&lt;/g;
+	$stringtoclean =~ s/>/&gt;/g;
+	$stringtoclean =~ s/|//g;
+
+	# To avoid onload="
+	$stringtoclean =~ s/onload//g;
+	return $stringtoclean;
+}
+
 
 #-------------------------------------------------------
 # MAIN
@@ -124,6 +145,12 @@ elsif ($Url =~ /url=(.+)$/) { $Url=$1; }
 $Url = DecodeEncodedString($Url);
 $UrlParam=$Url;
 
+# Sanitize parameters
+$Tag=CleanXSS($Tag);
+$Key=CleanXSS($Key);
+$UrlParam=CleanXSS($UrlParam);
+
+
 if (! $UrlParam) {
         error("Error: Bad use of $PROG. To redirect an URL with $PROG, use the following syntax:<br><i>/cgi-bin/$PROG.pl?url=http://urltogo</i>");
 }
