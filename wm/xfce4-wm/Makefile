# $NetBSD: Makefile,v 1.59 2017/06/18 22:56:55 youri Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.13.0
DISTNAME=	xfwm4-${VERSION}
PKGNAME=	xfce4-wm-${VERSION}
CATEGORIES=	wm
MASTER_SITES+=	http://archive.xfce.org/src/xfce/xfwm4/${VERSION:R}/

HOMEPAGE=	http://docs.xfce.org/xfce/xfwm4/start
COMMENT=	Xfce window manager

.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
