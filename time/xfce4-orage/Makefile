# $NetBSD: Makefile,v 1.4 2009/08/26 19:57:05 sno Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	orage-${XFCE4_VERSION}
PKGNAME=	xfce4-orage-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	time
COMMENT=	Xfce time managing application

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
