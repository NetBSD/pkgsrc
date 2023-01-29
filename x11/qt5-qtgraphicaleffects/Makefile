# $NetBSD: Makefile,v 1.54 2023/01/29 21:18:20 ryoon Exp $

DISTNAME=	qtgraphicaleffects-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtgraphicaleffects-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for Graphics effects

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
