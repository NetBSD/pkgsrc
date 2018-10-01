# $NetBSD: Makefile,v 1.28 2018/10/01 17:44:47 adam Exp $

DISTNAME=	qtgraphicaleffects-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtgraphicaleffects-${QTVERSION}
COMMENT=	Qt5 module for Graphics effects

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
