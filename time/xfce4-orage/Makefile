# $NetBSD: Makefile,v 1.3 2008/12/18 14:26:32 hira Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	orage-${XFCE4_VERSION}
PKGNAME=	xfce4-orage-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	time
COMMENT=	Xfce time managing application

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
