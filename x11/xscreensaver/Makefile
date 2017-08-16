# $NetBSD: Makefile,v 1.110 2017/08/16 07:33:39 wiz Exp $

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome<4.14

.include "Makefile.common"
.include "options.mk"
.include "../../textproc/libxml2/buildlink3.mk"

CONFIGURE_ARGS+=	--without-gtk
#CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

EGDIR=			${PREFIX}/share/examples/xscreensaver
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}

# use pipes from 5.17, the new version is too slow
post-extract:
	${CP} ${FILESDIR}/pipes.c ${WRKSRC}/hacks/glx

INSTALLATION_DIRS=	${EGDIR}/pam.d

post-install:
	${INSTALL_DATA} ${FILESDIR}/pam-xscreensaver-NetBSD \
	    ${DESTDIR}${EGDIR}/pam.d/xscreensaver-NetBSD

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
