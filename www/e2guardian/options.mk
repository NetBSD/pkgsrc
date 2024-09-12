# $NetBSD: options.mk,v 1.4 2024/09/12 13:58:15 sborrill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.e2guardian
PKG_SUPPORTED_OPTIONS=	debug email commandline clamd icap
PKG_SUGGESTED_OPTIONS=	email

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--with-dgdebug
.endif

##
## Enables reporting by email
##
.if !empty(PKG_OPTIONS:Memail)
CONFIGURE_ARGS+=	--enable-email
.endif

##
## Enable support for ICAP AV server content scanner
##
PLIST_VARS+=		icap
.if !empty(PKG_OPTIONS:Micap)
CONFIGURE_ARGS+=	--enable-icap
PLIST.icap=		yes
EGFILES_EXTRA+=		contentscanners/icap.conf
.endif

# PLIST.avscan is shared between content scanners
PLIST_VARS+=		avscan
##
## Enable command line content scanner
##
PLIST_VARS+=		cli
.if !empty(PKG_OPTIONS:Mcommandline)
CONFIGURE_ARGS+=	--enable-commandline
PLIST.cli=		yes
PLIST.avscan=		yes
EGFILES_EXTRA+=		contentscanners/commandlinescan.conf
.endif

##
## Enable ClamD content scanner
##
PLIST_VARS+=		clamd
.if !empty(PKG_OPTIONS:Mclamd)
CONFIGURE_ARGS+=	--enable-clamd
PLIST.clamd=		yes
PLIST.avscan=		yes
EGFILES_EXTRA+=		contentscanners/clamdscan.conf
.endif

.if !empty(PLIST.avscan)
EGFILES_LIST+=		${.CURDIR}/files/configfiles.avscan
.endif
