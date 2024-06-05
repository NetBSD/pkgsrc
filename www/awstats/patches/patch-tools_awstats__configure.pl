$NetBSD: patch-tools_awstats__configure.pl,v 1.2 2024/06/05 20:27:46 hauke Exp $

Fix paths.

--- tools/awstats_configure.pl.orig	2019-06-27 09:30:40.000000000 +0000
+++ tools/awstats_configure.pl
@@ -28,12 +28,12 @@ $AWSTATS_MODEL_CONFIG
 $AWSTATS_DIRDATA_PATH
 /;
 $AWSTATS_PATH='';
-$AWSTATS_ICON_PATH='/usr/local/awstats/wwwroot/icon';
-$AWSTATS_CSS_PATH='/usr/local/awstats/wwwroot/css';
-$AWSTATS_CLASSES_PATH='/usr/local/awstats/wwwroot/classes';
-$AWSTATS_CGI_PATH='/usr/local/awstats/wwwroot/cgi-bin';
-$AWSTATS_MODEL_CONFIG='/etc/awstats/awstats.model.conf';		# Used only when configure ran on linux
-$AWSTATS_DIRDATA_PATH='/var/lib/awstats';						# Used only when configure ran on linux
+$AWSTATS_ICON_PATH='@PREFIX@/awstats/icon';
+$AWSTATS_CSS_PATH='@PREFIX@/awstats/css';
+$AWSTATS_CLASSES_PATH='@PREFIX@/awstats/classes';
+$AWSTATS_CGI_PATH='@PREFIX@/awstats/cgi-bin';
+$AWSTATS_MODEL_CONFIG='@PKG_SYSCONFDIR@/awstats.model.conf';		# Used only when configure ran on linux
+$AWSTATS_DIRDATA_PATH='@VARBASE@/awstats';						# Used only when configure ran on linux
 
 
 
@@ -63,6 +63,7 @@ use vars qw/
 '/etc/httpd/httpd.conf',
 '/usr/local/apache/conf/httpd.conf',
 '/usr/local/apache2/conf/httpd.conf',
+'@PKG_SYSCONFBASE@/httpd/httpd.conf',
 );
 
 use vars qw/
@@ -308,13 +309,13 @@ if ($OS eq 'linux') {
 	$AWSTATS_PATH=`pwd`; $AWSTATS_PATH =~ s/[\r\n]//;
 	$AWSTATS_PATH=~s/tools[\\\/]?$//;
 	$AWSTATS_PATH=~s/[\\\/]$//;
-	if ($AWSTATS_PATH ne '/usr/local/awstats') {
-		print "Warning: AWStats standard directory on Linux OS is '/usr/local/awstats'.\n";
+	if ($AWSTATS_PATH ne '@PREFIX@/awstats') {
+		print "Warning: AWStats standard directory on Linux OS is '@PREFIX@/awstats'.\n";
 		print "If you want to use standard directory, you should first move all content\n";
 		print "of AWStats distribution from current directory:\n";
 		print "$AWSTATS_PATH\n";
 		print "to standard directory:\n";
-		print "/usr/local/awstats\n";
+		print "@PREFIX@/awstats\n";
 		print "And then, run configure.pl from this location.\n";
 		print "Do you want to continue setup from this NON standard directory [yN] ? ";
 		my $bidon='';
@@ -323,23 +324,23 @@ if ($OS eq 'linux') {
 			print "configure.pl aborted.\n";
 			exit 1;
 		}
-		$AWSTATS_ICON_PATH="$AWSTATS_PATH/wwwroot/icon";
-		$AWSTATS_CSS_PATH="$AWSTATS_PATH/wwwroot/css";
-		$AWSTATS_CLASSES_PATH="$AWSTATS_PATH/wwwroot/classes";
-		$AWSTATS_CGI_PATH="$AWSTATS_PATH/wwwroot/cgi-bin";
+		$AWSTATS_ICON_PATH="$AWSTATS_PATH/icon";
+		$AWSTATS_CSS_PATH="$AWSTATS_PATH/css";
+		$AWSTATS_CLASSES_PATH="$AWSTATS_PATH/classes";
+		$AWSTATS_CGI_PATH="$AWSTATS_PATH/cgi-bin";
 	}
 }
 elsif ($OS eq 'macosx') {
 	$AWSTATS_PATH=`pwd`; $AWSTATS_PATH =~ s/[\r\n]//;
 	$AWSTATS_PATH=~s/tools[\\\/]?$//;
 	$AWSTATS_PATH=~s/[\\\/]$//;
-	if ($AWSTATS_PATH ne '/Library/WebServer/awstats') {
-		print "Warning: AWStats standard directory on macOS is '/Library/WebServer/awstats'.\n";
+	if ($AWSTATS_PATH ne '@PREFIX@/awstats') {
+		print "Warning: AWStats standard directory on macOS is '@PREFIX@/awstats'.\n";
 		print "If you want to use standard directory, you should first move all content\n";
 		print "of AWStats distribution from current directory:\n";
 		print "$AWSTATS_PATH\n";
 		print "to standard directory:\n";
-		print "/Library/WebServer/awstats\n";
+		print "@PREFIX@/awstats\n";
 		print "And then, run configure.pl from this location.\n";
 		print "Do you want to continue setup from this NON standard directory [yN] ? ";
 		my $bidon='';
@@ -348,10 +349,10 @@ elsif ($OS eq 'macosx') {
 			print "configure.pl aborted.\n";
 			exit 1;
 		}
-		$AWSTATS_ICON_PATH="$AWSTATS_PATH/wwwroot/icon";
-		$AWSTATS_CSS_PATH="$AWSTATS_PATH/wwwroot/css";
-		$AWSTATS_CLASSES_PATH="$AWSTATS_PATH/wwwroot/classes";
-		$AWSTATS_CGI_PATH="$AWSTATS_PATH/wwwroot/cgi-bin";
+		$AWSTATS_ICON_PATH="$AWSTATS_PATH/icon";
+		$AWSTATS_CSS_PATH="$AWSTATS_PATH/css";
+		$AWSTATS_CLASSES_PATH="$AWSTATS_PATH/classes";
+		$AWSTATS_CGI_PATH="$AWSTATS_PATH/cgi-bin";
 	}
 }
 elsif ($OS eq 'windows') {
@@ -420,6 +421,7 @@ if (! scalar keys %ApacheConfPath) {
 		print "\n".($bidon?"Now, enter":"Enter")." full config file path of your Web server.\n";
 		print "Example: /etc/httpd/httpd.conf\n";
 		print "Example: /usr/local/apache2/conf/httpd.conf\n";
+		print "Example: @PKG_SYSCONFBASE@/httpd/httpd.conf\n";
 		print "Example: c:\\Program files\\apache group\\apache\\conf\\httpd.conf\n";
 		$bidon='';
 		while ($bidon ne 'none' && ! -f "$bidon") {
@@ -545,8 +547,8 @@ EOF
 # -----------------------------
 my $modelfile='';
 if ($OS eq 'linux') 		{ 
-	if (-f "$AWSTATS_PATH/wwwroot/cgi-bin/awstats.model.conf") {
-		$modelfile="$AWSTATS_PATH/wwwroot/cgi-bin/awstats.model.conf";
+	if (-f "@PKG_SYSCONFDIR@/awstats.model.conf") {
+		$modelfile="@PKG_SYSCONFDIR@/awstats.model.conf";
 	}
 	else {
 		$modelfile="$AWSTATS_MODEL_CONFIG";
@@ -554,7 +556,7 @@ if ($OS eq 'linux') 		{ 
 	}
 }
 elsif ($OS eq "macosx") 		{ 
-	$modelfile="$AWSTATS_PATH/wwwroot/cgi-bin/awstats.model.conf";
+	$modelfile="@PKG_SYSCONFDIR@/awstats.model.conf";
 }
 elsif ($OS eq 'windows')	{ $modelfile="$AWSTATS_PATH\\wwwroot\\cgi-bin\\awstats.model.conf"; }
 else						{ $modelfile="$AWSTATS_PATH\\wwwroot\\cgi-bin\\awstats.model.conf"; }
@@ -606,11 +608,11 @@ if ($bidon =~ /^y/i) {
 	if ($OS eq 'linux') 		{
 		print "\n-----> Define config file path\n";
 		print "In which directory do you plan to store your config file(s) ?\n";
-		print "Default: /etc/awstats\n";
+		print "Default: @PKG_SYSCONFDIR@\n";
 		my $bidon='';
 		print "Directory path to store config file(s) (Enter for default):\n> ";
 		$bidon=<STDIN>; chomp $bidon;
-		if (! $bidon) { $bidon = "/etc/awstats"; }
+		if (! $bidon) { $bidon = "@PKG_SYSCONFDIR@"; }
 		my $configdir=$bidon;
 		if (! -d $configdir) {
 			# Create the directory for config files
