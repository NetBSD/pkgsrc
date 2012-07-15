# $NetBSD: Makefile,v 1.16 2012/07/15 08:22:57 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	orage-${XFCE4_VERSION}
PKGNAME=	xfce4-orage-${XFCE4_VERSION}
PKGREVISION=	10
CATEGORIES=	time
COMMENT=	Xfce time managing application

CONFIGURE_ARGS+=	--disable-libxfce4mcs

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
