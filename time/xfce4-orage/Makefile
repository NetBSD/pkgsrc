# $NetBSD: Makefile,v 1.33 2015/06/29 15:03:01 youri Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.12.1
DISTNAME=	orage-${VERSION}
PKGNAME=	xfce4-orage-${VERSION}
CATEGORIES=	time
MASTER_SITES=	http://archive.xfce.org/src/apps/orage/4.12/

HOMEPAGE=	http://www.kolumbus.fi/~w408237/orage/
COMMENT=	Xfce time managing application

CONFIGURE_ARGS+=	--disable-libxfce4mcs

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${PREFIX}/libexec/xfce4/panel-plugins
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/panel-plugins

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
