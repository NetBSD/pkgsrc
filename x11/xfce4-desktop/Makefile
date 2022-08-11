# $NetBSD: Makefile,v 1.94 2022/08/11 05:09:34 gutteridge Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.16.0
DISTNAME=	xfdesktop-${VERSION}
PKGNAME=	xfce4-desktop-${VERSION}
CATEGORIES=	x11
MASTER_SITES+=	https://archive.xfce.org/src/xfce/xfdesktop/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/xfdesktop/start
COMMENT=	Xfce desktop background manager

USE_LANGUAGES=	c99

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

.include "../../devel/libwnck3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
