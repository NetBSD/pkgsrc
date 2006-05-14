# $NetBSD: options.mk,v 1.1 2006/05/14 18:55:50 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xscreensaver
PKG_SUPPORTED_OPTIONS=	pam xscreensaver-webcollage

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif

.if !empty(PKG_OPTIONS:Mxscreensaver-webcollage)
PLIST_SRC=	PLIST.webcollage PLIST
.else
post-install:
	${RM} ${PREFIX}/libexec/xscreensaver/config/webcollage.xml
	${RM} ${PREFIX}/libexec/xscreensaver/webcollage
	${RM} ${PREFIX}/man/man1/webcollage.1
.endif
