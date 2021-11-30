# $NetBSD: Makefile,v 1.85 2021/11/30 14:13:29 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.16.1
DISTNAME=	xfwm4-${VERSION}
PKGNAME=	xfce4-wm-${VERSION}
CATEGORIES=	wm
MASTER_SITES+=	https://archive.xfce.org/src/xfce/xfwm4/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/xfwm4/start
COMMENT=	Xfce window manager

.include "../../devel/libwnck3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXpresent/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
