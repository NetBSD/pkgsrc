# $NetBSD: Makefile,v 1.34 2013/06/04 22:17:34 tron Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.6.0

DISTNAME=	xfce4-notes-plugin-${XFCE4_VERSION}
PKGREVISION=	17
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-notes-plugin/
COMMENT=	Xfce notes plugin

LDFLAGS.DragonFly=	-lm -lX11

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
