# $NetBSD: options.mk,v 1.2 2016/09/19 13:20:43 sborrill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dansguardian
PKG_SUPPORTED_OPTIONS=	debug email commandline clamd
PKG_SUGGESTED_OPTIONS=	email

.include "../../mk/bsd.options.mk"

##
## switch on debug build mode
##
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--with-dgdebug
.endif

##
## Enables reporting by email
##
.if !empty(PKG_OPTIONS:Memail)
CONFIGURE_ARGS+=	--enable-email
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
