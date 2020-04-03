# $NetBSD: Makefile,v 1.121 2020/04/03 20:49:16 wiz Exp $

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

INSTALLATION_DIRS=	${EGDIR}/pam.d

post-install:
	${INSTALL_DATA} ${FILESDIR}/pam-xscreensaver-NetBSD \
	    ${DESTDIR}${EGDIR}/pam.d/xscreensaver-NetBSD

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
