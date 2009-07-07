# $NetBSD: options.mk,v 1.5 2009/07/07 17:28:04 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xscreensaver
PKG_SUPPORTED_OPTIONS=	pam xscreensaver-webcollage

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--without-shadow
.if ${OPSYS} == "NetBSD"
# needed to read shadow passwords
DEPENDS+=	pam-pwauth_suid-*:../../security/pam-pwauth_suid
.endif
.else
CONFIGURE_ARGS+=	--without-pam
# configure should figure out
#CONFIGURE_ARGS+=	--without-shadow
.endif

.if !empty(PKG_OPTIONS:Mxscreensaver-webcollage)
PLIST_SRC=	PLIST.webcollage PLIST
.else
post-install: delwebcollage
delwebcollage:
	rm ${DESTDIR}${PREFIX}/libexec/xscreensaver/config/webcollage.xml
	rm ${DESTDIR}${PREFIX}/libexec/xscreensaver/webcollage
	rm ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/webcollage.6
.endif
