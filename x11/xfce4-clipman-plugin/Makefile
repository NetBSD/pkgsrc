# $NetBSD: Makefile,v 1.25 2012/09/07 19:17:54 adam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.8.0

DISTNAME=	xfce4-clipman-plugin-${XFCE4_VERSION}
PKGREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-clipman-plugin/
COMMENT=	Xfce clipboard plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
