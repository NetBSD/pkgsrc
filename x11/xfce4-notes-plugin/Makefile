# $NetBSD: Makefile,v 1.27 2012/09/07 19:17:55 adam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.6.0

DISTNAME=	xfce4-notes-plugin-${XFCE4_VERSION}
PKGREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-notes-plugin/
COMMENT=	Xfce notes plugin

LDFLAGS.DragonFly=	-lm -lX11

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
