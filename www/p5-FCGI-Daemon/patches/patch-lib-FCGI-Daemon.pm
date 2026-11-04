$NetBSD: patch-lib-FCGI-Daemon.pm,v 1.1 2026/11/04 13:46:53 ast Exp $

Add an option -X to enable debugging.

Unlink files without testing for existence as we ignore exit status
anyway.

Use POSIX calls setgid and setuid to non-root user when running as
"root" daemon.

Use only $EFFECTIVE_USER_ID to discrimiate if we need to set[gu]id
and don't install signal handlers INT and TERM as FCGI::ProcManager
does that.

Close socket when running as root (manager) and remove files in
pm_die() routine.

Instead of using a non-portable /proc/$$/status read to get memory
usage on Linux, use a non-portable /bin/ps command on BSD platforms.

Mention NetBSD and pkgsrc in POD.

Make sure all test pass.
 

--- lib/FCGI/Daemon.pm.orig	2022-02-06 15:23:10.000000000 +0000
+++ lib/FCGI/Daemon.pm	2022-07-28 16:42:18.127502146 +0000
@@ -6,6 +6,7 @@
 package FCGI::Daemon;
 our $VERSION = '0.20220206';
 use 5.14.2;
+use POSIX;
 use English '-no_match_vars';
 use BSD::Resource;                      # on Debian available as libbsd-resource-perl
 use FCGI 0.82;                          # on Debian available as libfcgi-perl
@@ -25,6 +26,7 @@
 =cut
 
 my %o;
+my $DEBUG = 0;
 
 __PACKAGE__->run() unless caller();     # modulino i.e. executable rather than module
 
@@ -39,9 +41,7 @@
 sub dieif {
     if($ARG[0]){
         my $err=$ARG[1];
-        for my $f ( @o{'pidfile','sockfile'} ) {
-            unlink $f if -f $f; 
-        }        
+        unlink $o{$_} for qw(pidfile sockfile);
         print "Error - $err:\n",$ARG[0],"\n";
         exit 1;
     }
@@ -51,7 +51,7 @@
     Modulino-style main routine
 =cut
 sub run {
-    getopts('hde:f:q:p:s:g:u:m:c:l:w:',\%o) or help(0);
+    getopts('hde:f:q:p:s:g:u:m:c:l:w:X',\%o) or help(0);
     help(2) if $o{'h'};
 
     $o{sockfile}=$o{'s'}||'/var/run/fcgi-daemon.sock';
@@ -63,21 +63,18 @@
     $o{max_evals}=defined $o{'e'} ? $o{'e'} : 10240;   #max evals before exit - paranoid to free memory if leaks
     $o{file_pattern}=$o{'f'}||qr{\.pl};
     $o{leak_threshold}=$o{'l'}||1.3;
+    $DEBUG++ if $o{'X'};
 
-    if($REAL_USER_ID==$EFFECTIVE_USER_ID and $EFFECTIVE_USER_ID==0){        # if run as root
+    if($EFFECTIVE_USER_ID==0){
         $o{gid}=$o{g}||'www-data'; $o{gid_num}=scalar getgrnam($o{gid});
         $o{uid}=$o{u}||'www-data'; $o{uid_num}=scalar getpwnam($o{uid});
     }
 
-    local $SIG{INT}= local $SIG{TERM}= sub{
-        # actually FCGI::ProcManager override our TERM handler so .sock and .pid files will be removed only by sysv script... :(
-        $o{fcgi_pm}->pm_remove_pid_file() if $o{fcgi_pm};
-        for my $f ( @o{'pidfile','sockfile'} ) {
-            unlink $f if -f $f; 
-        }    
-        $o{fcgi_pm}->pm_die() if $o{fcgi_pm};   #pm_die() does not return
-        exit 0;
-    };
+    if ($DEBUG) {
+        use Data::Dumper;
+        $Data::Dumper::Indent = 1;
+        warn Data::Dumper->Dump([\%o],['o']);
+    }
 
     # daemonize
     if($o{'d'}){
@@ -85,10 +82,10 @@
         local $PROGRAM_NAME='FCGI::Daemon';
         defined(my $pid=fork) or die "Can't fork: $!";
         exit if $pid;
-        eval {use POSIX qw(setsid); POSIX::setsid();} or die q{Can't start a new session: }.$OS_ERROR;
+        POSIX::setsid() or die q{Can't start a new session: }.$OS_ERROR;
         open *STDIN,'<','/dev/null';
         open *STDOUT,'>>','/dev/null';
-        open *STDERR,'>>','/dev/null';
+        open *STDERR,'>>','/dev/null' unless $DEBUG;
         umask 022;
     }
 
@@ -98,32 +95,24 @@
                                         pid_fname=>$o{pidfile}
                                       });
     print "Opening socket $o{sockfile}\n";
+    $o{socket_fh} = FCGI::OpenSocket($o{sockfile},$o{prefork}*$o{queue});
     my $rqst=FCGI::Request(\*STDIN,\*STDOUT,\*STDERR,\%req_env,
-             FCGI::OpenSocket($o{sockfile},$o{prefork}*$o{queue}),
-             FCGI::FAIL_ACCEPT_ON_INTR())
+             $o{socket_fh}, FCGI::FAIL_ACCEPT_ON_INTR())
         or die "Error: Unable to create FCGI::Request...";
 
-    if(defined $o{gid_num} and defined $o{uid_num}){                # if run as root
-        chown $o{uid_num},$o{gid_num},$o{sockfile}                  # chown SOCKfile
-            or dieif($OS_ERROR,'Unable to chown SOCKfile');
+    # drop privileges if run as root
+    if(defined $o{uid_num} && defined $o{gid_num}) {
+        my $old_euid = $EFFECTIVE_USER_ID;
+        chown $o{uid_num},$o{gid_num},$o{sockfile}
+            or dieif($OS_ERROR,'Unable to chown SOCKfile '.$o{sockfile});
+        POSIX::setgid($o{gid_num}) or dieif($OS_ERROR,
+            "UID $old_euid couldn't change group to $o{gid} ($o{gid_num})");
+        POSIX::setuid($o{uid_num}) or dieif($OS_ERROR,
+            "UID $old_euid couldn't change user to $o{uid} ($o{uid_num})");
     }
 
     $o{fcgi_pm}->pm_manage();   # from now on we are worker process
 
-    # drop privileges if run as root
-    if(defined $o{gid_num} and defined $o{uid_num}){
-       my $gid = getgrnam($o{gid});
-       $EFFECTIVE_GROUP_ID = "$gid $gid";
-       dieif($OS_ERROR,'Unable to effective group_id to '.$o{gid});
-       $REAL_GROUP_ID = $gid;
-       dieif($OS_ERROR,'Unable to change real group_id to '.$o{gid});
-       my $uid = getpwnam($o{uid});
-       $EFFECTIVE_USER_ID = $uid;
-       dieif($OS_ERROR,'Unable to change effective user_id to '.$o{uid});
-       $REAL_USER_ID  = $uid;
-       dieif($OS_ERROR,'Unable to change real user_id to '.$o{uid});
-    }
-
     ## set rlimit(s)
     setrlimit(RLIMIT_AS, $o{rlimit_vmem}, $o{rlimit_vmem})
       or warn "Unable to set RLIMIT_AS.\n";
@@ -181,21 +170,37 @@
                 delete $main::{$_};
             }
 
-            if(open my $STAT,'<',"/proc/$$/status"){
-                my %stat;
-                while(my ($k,$v)=split /\:\s+/,<$STAT>){
-                    chop $v;
-                    $stat{$k}=$v;
+            exit unless --$o{max_evals};
+
+            # exit if child takes too much resident memory
+            my %stat = ();
+            if ( $OSNAME =~ m{bsd}oi ) {
+                if (open my $STAT,'-|',"/bin/ps -o vsz,rss -p $$") {
+                    while(<$STAT>) {
+                        if ( m{^\s*(\d+)\s+(\d+)$}o ) {
+                             $stat{VmSize} = $1;
+                             $stat{VmRSS} = $2;
+                             last;
+                        }
+                    }
+                    close $STAT;
                 }
-                close $STAT;
-                # check if child takes too much resident memory and terminate if necessary
-                if($stat{VmSize}/$stat{VmRSS}<$o{leak_threshold}){
-                    print {*STDERR} 'fcgi-daemon :: terminating child - memory leak? '
-                    ."VmSize:$stat{VmSize}; VmRSS:$stat{VmRSS}; Ratio:".$stat{VmSize}/$stat{VmRSS};
-                    exit;
+            } else {
+                if(open my $STAT,'<',"/proc/$$/status"){
+                    while(my ($k,$v)=split /\:\s+/,<$STAT>){
+                        chop $v;
+                        $stat{$k}=$v;
+                    }
+                    close $STAT;
                 }
             }
-            exit unless --$o{max_evals};
+            if ( $stat{VmSize} && $stat{VmRSS}
+                   && ($stat{VmSize}/$stat{VmRSS}<$o{leak_threshold}) ) {
+                 die 'fcgi-daemon :: terminating child - memory leak? '
+                     ."VmSize:$stat{VmSize}; VmRSS:$stat{VmRSS}; Ratio:"
+                     .$stat{VmSize}/$stat{VmRSS};
+            }
+
             next REQ_LOOP;
         }
 
@@ -253,6 +258,24 @@
     return;
 }
 
+=head2 managing_init ()
+    close socket as manager
+=cut
+sub managing_init {
+    # manager (running as root) doesn't need to listen on the socket
+    close $o{socket_fh} if $EFFECTIVE_USER_ID==0;
+    return $o{fcgi_pm}->managing_init(shift @_);
+}
+
+=head2 pm_die()
+    exit cleanly
+=cut
+sub pm_die {
+    # manager (running as root) can remove these better
+    unlink $o{$_} for qw(pidfile sockfile);
+    return $o{fcgi_pm}->pm_die(shift @_);
+}
+
 # overriding process names
 sub FCGI::ProcManager::pm_change_process_name {
     my ($self,$name)=@_;
@@ -293,7 +316,7 @@
 CGI applications.
 
 Like mod_perl FCGI-Daemon stay persistent in memory and accelerate
-unmodified CGI applications written in Perl. 
+unmodified CGI applications written in Perl.
 
 FCGI-Daemon run CGI scripts with RLIMITs and predefined number of workers.
 
@@ -302,7 +325,7 @@
 
 FCGI-Daemon check for executable in path and correctly set PATH_INFO
 environment variable which is crucial for some CGI applications like
-fossil (L<http://fossil-scm.org>). 
+fossil (L<http://fossil-scm.org>).
 (Lack of this functionality make cgiwrap-fcgi.pl unsuitable for some scripts.)
 
 
@@ -351,6 +374,7 @@
   -u www-data                     # user name to become (if run as root)
   -g www-data                     # group name to become (if run as root)
   -d                              # daemonize (run in background)
+  -X                              # enable debugging
 
 All options are optional.
 
@@ -410,7 +434,7 @@
 
 =head1 COMPATIBILITY
 
-Tested only on GNU/Linux systems.
+Tested on GNU/Linux and NetBSD systems (pkgsrc).
 NOT tested and not expected to work on Windows.
 
 =head1 NOTES
