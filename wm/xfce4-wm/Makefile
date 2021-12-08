# $NetBSD: Makefile,v 1.86 2021/12/08 16:06:52 adam Exp $

PKGREVISION= 1
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
