# $NetBSD: Makefile,v 1.18 2017/02/12 06:26:15 ryoon Exp $

DISTNAME=	qtgraphicaleffects-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtgraphicaleffects-${QTVERSION}
PKGREVISION=	6
COMMENT=	Qt5 module for Graphics effects

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
