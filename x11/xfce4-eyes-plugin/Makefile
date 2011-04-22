# $NetBSD: Makefile,v 1.8 2011/04/22 13:42:28 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.4.0

DISTNAME=	xfce4-eyes-plugin-${XFCE4_VERSION}
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-eyes-plugin/
COMMENT=	Xfce eyes plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
