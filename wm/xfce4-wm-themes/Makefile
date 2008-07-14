# $NetBSD: Makefile,v 1.17 2008/07/14 12:56:14 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfwm4-themes-${XFCE4_VERSION}
PKGNAME=	xfce4-wm-themes-${XFCE4_VERSION}
CATEGORIES=	wm
COMMENT=	Xfce window manager themes

USE_DIRS+=	theme-1.1 xdg-1.1

.include "../../wm/xfce4-wm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
