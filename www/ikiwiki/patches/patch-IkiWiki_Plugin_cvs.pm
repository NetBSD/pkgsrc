$NetBSD: patch-IkiWiki_Plugin_cvs.pm,v 1.1 2013/01/28 04:30:15 schmonz Exp $

Bugfixes in `schmonz/cvs` I'd like to see merged:

* `6753235d`: Return bounded output from `rcs_diff()` when asked, as
  the API states.
* `e45175d5`: Always explicitly set CVS keyword substitution behavior.
  Fixes behavior when a text file is added under a name formerly
  used for a binary file.
* `b30cacdf`: If the previous working directory no longer exists after
  a CVS operation, don't try to `chdir()` back to it afterward.

--- IkiWiki/Plugin/cvs.pm.orig	2012-08-25 15:12:13.000000000 +0000
+++ IkiWiki/Plugin/cvs.pm
@@ -216,14 +216,12 @@ sub rcs_add ($) {
 
 	while ($file = pop @files_to_add) {
 		if (@files_to_add == 0) {
-			# file
 			cvs_runcvs('add', cvs_keyword_subst_args($file)) ||
-				warn("cvs add $file failed\n");
+				warn("cvs add file $file failed\n");
 		}
 		else {
-			# directory
 			cvs_runcvs('add', $file) ||
-				warn("cvs add $file failed\n");
+				warn("cvs add dir $file failed\n");
 		}
 	}
 }
@@ -396,11 +394,15 @@ sub rcs_diff ($;$) {
 	my @cvsps = `env TZ=UTC cvsps -q --cvs-direct -z 30 -g -s $rev`;
 	my $blank_lines_seen = 0;
 
+	# skip log, get to the diff
 	while (my $line = shift @cvsps) {
 		$blank_lines_seen++ if ($line =~ /^$/);
 		last if $blank_lines_seen == 2;
 	}
 
+	@cvsps = @cvsps[0..$maxlines-1]
+		if defined $maxlines && @cvsps > $maxlines;
+
 	if (wantarray) {
 		return @cvsps;
 	}
@@ -491,24 +493,53 @@ sub cvs_keyword_subst_args ($) {
 	my $filemime = File::MimeInfo::default($file);
 	# if (-T $file) {
 
-	if (defined($filemime) && $filemime eq 'text/plain') {
-		return ($file);
-	}
-	else {
-		return ('-kb', $file);
-	}
+	defined($filemime) && $filemime eq 'text/plain'
+		? return ('-kkv', $file)
+		: return ('-kb', $file);
 }
 
 sub cvs_runcvs(@) {
 	my @cmd = @_;
 	unshift @cmd, 'cvs', '-Q';
 
-	local $CWD = $config{srcdir};
+	# CVS can't operate outside a srcdir, so we're always setting $CWD.
+	# "local $CWD" restores the previous value when we go out of scope.
+	# Usually that's correct. But if we're removing the last file from
+	# a directory, the post-commit hook will exec in a working directory
+	# that's about to not exist (CVS will prune it).
+	#
+	# chdir() manually here, so we can selectively not chdir() back.
+
+	my $oldcwd = $CWD;
+	chdir($config{srcdir});
+
+	eval q{
+		use IPC::Open3;
+		use Symbol qw(gensym);
+		use IO::File;
+	};
+	error($@) if $@;
+
+	my $cvsout = '';
+	my $cvserr = '';
+	local *CATCHERR = IO::File->new_tmpfile;
+	my $pid = open3(gensym(), \*CATCHOUT, ">&CATCHERR", @cmd);
+	while (my $l = <CATCHOUT>) {
+		$cvsout .= $l
+			unless 1;
+	}
+	waitpid($pid, 0);
+	my $ret = $? >> 8;
+	seek CATCHERR, 0, 0;
+	while (my $l = <CATCHERR>) {
+		$cvserr .= $l
+			unless $l =~ /^cvs commit: changing keyword expansion /;
+	}
+
+	print STDOUT $cvsout;
+	print STDERR $cvserr;
 
-	open(my $savedout, ">&STDOUT");
-	open(STDOUT, ">", "/dev/null");
-	my $ret = system(@cmd);
-	open(STDOUT, ">&", $savedout);
+	chdir($oldcwd) if -d $oldcwd;
 
 	return ($ret == 0) ? 1 : 0;
 }
