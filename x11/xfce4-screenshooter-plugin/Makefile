# $NetBSD: Makefile,v 1.12 2012/07/15 08:23:01 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.0.0

DISTNAME=	xfce4-screenshooter-plugin-${XFCE4_VERSION}
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-screenshooter-plugin/
COMMENT=	Xfce screenshot plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
