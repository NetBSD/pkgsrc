# $NetBSD: Makefile,v 1.1.1.1 2003/12/13 19:23:43 jmmv Exp $
#

PKGNAME=	${DISTNAME:S/-/-demo-/}
COMMENT=	Screen saver and locker for the X window system (demo program)

CONFLICTS+=	xscreensaver<4.14 xscreensaver-gnome-[0-9]*

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=        --with-gtk=${BUILDLINK_PREFIX.gtk2}
CONFIGURE_ARGS+=        --with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

BUILD_DIRS=		${WRKSRC}/utils ${WRKSRC}/driver
INSTALL_DIRS=		${WRKSRC}/driver
INSTALL_TARGET=		install-gnome

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driver/xscreensaver-demo ${PREFIX}/bin

.include "../../devel/libglade2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/xscreensaver/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
