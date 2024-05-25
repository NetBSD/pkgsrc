# $NetBSD: Makefile,v 1.65 2024/05/25 14:21:21 adam Exp $

DISTNAME=	qtquickcontrols-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtquickcontrols-${QTVERSION}
COMMENT=	Qt5 module for QuickControls

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
