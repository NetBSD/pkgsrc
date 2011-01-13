# $NetBSD: Makefile,v 1.20 2011/01/13 13:36:50 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.6.0

DISTNAME=	xfce4-notes-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-notes-plugin/
COMMENT=	Xfce notes plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
