# $NetBSD: Makefile,v 1.11 2012/03/03 00:11:56 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.4.0

DISTNAME=	xfce4-eyes-plugin-${XFCE4_VERSION}
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-eyes-plugin/
COMMENT=	Xfce eyes plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
