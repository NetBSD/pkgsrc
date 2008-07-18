# $NetBSD: Makefile,v 1.4 2008/07/18 14:20:56 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.4

DISTNAME=	exo-${XFCE4_VERSION}
PKGNAME=	xfce4-exo-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce extension library

DEPENDS+=	p5-URI>=0:../../www/p5-URI

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
