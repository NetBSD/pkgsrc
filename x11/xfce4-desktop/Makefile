# $NetBSD: Makefile,v 1.114 2025/08/30 22:46:48 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.20.1
PKGREVISION=	4
DISTNAME=	xfdesktop-${VERSION}
PKGNAME=	xfce4-desktop-${VERSION}
CATEGORIES=	x11
MASTER_SITES+=	https://archive.xfce.org/src/xfce/xfdesktop/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/xfdesktop/start
COMMENT=	Xfce desktop background manager

USE_LANGUAGES=	c99
USE_TOOLS+=	gdbus-codegen

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

.include "../../devel/libwnck3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../x11/libxfce4windowing/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
