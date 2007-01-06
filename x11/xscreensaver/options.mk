# $NetBSD: options.mk,v 1.3 2007/01/06 19:53:40 rillig Exp $

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
	rm ${PREFIX}/libexec/xscreensaver/config/webcollage.xml
	rm ${PREFIX}/libexec/xscreensaver/webcollage
	rm ${PREFIX}/${PKGMANDIR}/man6/webcollage.6
.endif
