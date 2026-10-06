$NetBSD: patch-fcgiwrap.c,v 1.2 2026/10/06 03:15:00 riastradh Exp $

1. Appease -Werror=implicit-fallthrough.

2. Fix 100% CPU usage as soon as  child exits:
   https://github.com/gnosek/fcgiwrap/issues/18
   https://github.com/gnosek/fcgiwrap/pull/20

3-4. Fix races with SIGCHLD handler around access to nrunning.

--- fcgiwrap.c.orig	2013-02-03 13:25:17.000000000 +0000
+++ fcgiwrap.c
@@ -553,7 +553,7 @@ static void handle_fcgi_request(void)
 
 			execl(filename, filename, (void *)NULL);
 			cgi_error("502 Bad Gateway", "Cannot execute script", filename);
-
+			break;
 		default: /* parent */
 			close(pipe_in[0]);
 			close(pipe_out[1]);
@@ -605,7 +605,7 @@ static void sigchld_handler(int dummy)
 {
 	int status;
 
-	while ((dummy = waitpid(-1, &status, WNOHANG)) != -1) {
+	while ((dummy = waitpid(-1, &status, WNOHANG)) > 0) {
 		/* sanity check */
 		if (nrunning > 0)
 			nrunning--;
@@ -619,17 +619,22 @@ static void sigchld_handler(int dummy)
 static void prefork(int nchildren)
 {
 	int startup = 1;
+	sigset_t mask, omask;
 
 	if (nchildren == 1) {
 		return;
 	}
 
+	sigemptyset(&mask);
+	sigaddset(&mask, SIGCHLD);
+	sigprocmask(SIG_BLOCK, &mask, &omask);
 	signal(SIGCHLD, sigchld_handler);
 
 	while (1) {
 		while (nrunning < nchildren) {
 			pid_t pid = fork();
 			if (pid == 0) {
+				sigprocmask(SIG_SETMASK, &omask, NULL);
 				return;
 			} else if (pid != -1) {
 				nrunning++;
@@ -644,7 +649,7 @@ static void prefork(int nchildren)
 			}
 		}
 		startup = 0;
-		pause();
+		sigsuspend(&omask);
 	}
 }
 
