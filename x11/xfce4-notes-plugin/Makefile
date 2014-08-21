# $NetBSD: Makefile,v 1.39 2014/08/21 14:33:46 jperkin Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.6.0

DISTNAME=	xfce4-notes-plugin-${XFCE4_VERSION}
PKGREVISION=	21
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-notes-plugin/
COMMENT=	Xfce notes plugin

LDFLAGS.DragonFly=	-lm -lX11
LDFLAGS.SunOS+=		-lm -lX11

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
