# $NetBSD: Makefile,v 1.18 2005/06/28 10:03:14 wiz Exp $
#

PKGNAME=	${DISTNAME:S/-/-demo-/}
COMMENT=	Demo viewer and configuration tool for xscreensaver

CONFLICTS+=	xscreensaver<4.14 xscreensaver-gnome-[0-9]*

USE_DIRS+=	xdg-1.1

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=        --with-gtk=${BUILDLINK_PREFIX.gtk2}
CONFIGURE_ARGS+=        --with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

BUILD_DIRS=		${WRKSRC}/utils ${WRKSRC}/driver
INSTALL_DIRS=		${WRKSRC}/driver
INSTALL_TARGET=		install-gnome

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driver/xscreensaver-demo ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driver/xscreensaver-demo.man \
		       ${PREFIX}/man/man1/xscreensaver-demo.1

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
