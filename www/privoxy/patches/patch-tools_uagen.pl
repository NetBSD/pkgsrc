$NetBSD: patch-tools_uagen.pl,v 1.1 2026/08/13 18:17:58 wiz Exp $

Replace hardcoded paths with paths configured by pkgsrc.

--- tools/uagen.pl.orig	2026-08-12 13:09:18.065429443 +0000
+++ tools/uagen.pl
@@ -41,8 +41,8 @@ use constant {
 
    UAGEN_VERSION       => 'uagen 1.2.7',
 
-   UAGEN_LOGFILE       => '/var/log/uagen.log',
-   ACTION_FILE         => '/etc/privoxy/user-agent.action',
+   UAGEN_LOGFILE       => '@VARBASE@/log/uagen.log',
+   ACTION_FILE         => '@PKG_SYSCONFDIR@/user-agent.action',
    MOZILLA_PREFS_FILE  => '',
    SILENT              =>  0,
    NO_LOGGING          =>  0,
@@ -477,7 +477,7 @@ used by many Mozilla browsers.
 =head1 OPTIONS
 
 B<--action-file> I<action_file> Privoxy action file to write the
-generated actions into. Default is /etc/privoxy/user-agent.action.
+generated actions into. Default is @PKG_SYSCONFDIR@/user-agent.action.
 
 B<--action-injection> Don't generate a new action file from scratch,
 but read an old one and just replace the action values. Useful
