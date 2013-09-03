$NetBSD: patch-Makefile.PL,v 1.1 2013/09/03 10:08:26 adam Exp $

Introduce ETCDIR, where real configuration files are installed.

--- Makefile.PL.orig	2013-09-02 20:53:21.000000000 +0000
+++ Makefile.PL
@@ -4,7 +4,7 @@ use ExtUtils::MakeMaker;
 
 use strict;
 
-my @ALLOWED_ARGS = ('LOGFILE','BINDIR','CONFDIR','HTMLDIR','BASEURL','DOCDIR','MANDIR','QUIET','INSTALLDIRS','DESTDIR');
+my @ALLOWED_ARGS = ('LOGFILE','BINDIR','ETCDIR','CONFDIR','HTMLDIR','BASEURL','DOCDIR','MANDIR','QUIET','INSTALLDIRS','DESTDIR');
 
 # Parse command line arguments and store them as environment variables
 while ($_ = shift) {
@@ -24,6 +24,7 @@ if (! -d $default_log ) {
 # Default install path
 my $LOGFILE = $ENV{LOGFILE} || $default_log;
 my $BINDIR = $ENV{BINDIR} || '/usr/local/bin';
+my $ETCDIR = $ENV{ETCDIR} || '/etc/squidanalyzer';
 my $CONFDIR = $ENV{CONFDIR} || '/etc/squidanalyzer';
 my $HTMLDIR = $ENV{HTMLDIR} || '/var/www/squidanalyzer';
 my $BASEURL = $ENV{BASEURL} || '/squidreport';
@@ -129,7 +130,7 @@ close(INST);
 `chmod 755 install_all.sh`;
 
 # Change path into the default configuration file
-`perl -p -i -e 's#/etc/squidanalyzer#$CONFDIR#' etc/squidanalyzer.conf squid-analyzer`;
+`perl -p -i -e 's#/etc/squidanalyzer#$ETCDIR#' etc/squidanalyzer.conf squid-analyzer`;
 `perl -p -i -e 's#^Output.*#Output	$HTMLDIR#' etc/squidanalyzer.conf`;
 `perl -p -i -e 's#^LogFile.*#LogFile	$LOGFILE#' etc/squidanalyzer.conf`;
 `perl -p -i -e 's#^WebUrl.*#WebUrl	$BASEURL#' etc/squidanalyzer.conf`;
