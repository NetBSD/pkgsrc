# $NetBSD: Makefile,v 1.47 2020/11/21 11:22:32 adam Exp $

DISTNAME=	qtgraphicaleffects-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtgraphicaleffects-${QTVERSION}
COMMENT=	Qt5 module for Graphics effects

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
