# $NetBSD: Makefile,v 1.17 2008/07/14 12:56:19 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-mcs-plugins-${XFCE4_VERSION}
PKGNAME=	xfce4-mcs-plugins-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce settings manager plugins

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-manager/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
