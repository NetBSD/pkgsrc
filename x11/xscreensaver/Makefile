# $NetBSD: Makefile,v 1.130 2021/05/24 19:56:06 wiz Exp $

COMMENT=	Screen saver and locker for the X window system
PKGREVISION=	3

CONFLICTS+=	xscreensaver-gnome<4.14

.include "Makefile.common"
.include "options.mk"
.include "../../textproc/libxml2/buildlink3.mk"

CONFIGURE_ARGS+=	--without-gtk
#CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

INSTALLATION_DIRS=	share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
