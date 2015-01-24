# $NetBSD: options.mk,v 1.9 2015/01/24 06:09:13 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xscreensaver
PKG_SUPPORTED_OPTIONS=	pam webcollage opengl
PKG_SUGGESTED_OPTIONS=	opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--without-shadow
.  if ${OPSYS} == "NetBSD"
# needed to read shadow passwords
DEPENDS+=	pam-pwauth_suid-[0-9]*:../../security/pam-pwauth_suid
.  endif
.else
CONFIGURE_ARGS+=	--without-pam
# configure should figure out
#CONFIGURE_ARGS+=	--without-shadow
.endif

PLIST_SRC=	PLIST
.if !empty(PKG_OPTIONS:Mwebcollage)
PLIST_SRC+=	PLIST.webcollage
.else
post-install: delwebcollage
delwebcollage:
	rm ${DESTDIR}${PREFIX}/libexec/xscreensaver/config/webcollage.xml
	rm ${DESTDIR}${PREFIX}/libexec/xscreensaver/webcollage
	rm ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/webcollage.6
.endif

.if !empty(PKG_OPTIONS:Mopengl)
PLIST_SRC+=		PLIST.opengl
CONFIGURE_ARGS+=	--with-gl
CONFIGURE_ARGS+=	--with-gle
.include "../../graphics/gle/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gl
CONFIGURE_ARGS+=	--without-gle
.endif
