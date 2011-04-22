# $NetBSD: Makefile,v 1.20 2011/04/22 13:42:14 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.8.0

DISTNAME=	xfce4-clipman-plugin-${XFCE4_VERSION}
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-clipman-plugin/
COMMENT=	Xfce clipboard plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
