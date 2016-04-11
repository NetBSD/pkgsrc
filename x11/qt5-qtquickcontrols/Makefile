# $NetBSD: Makefile,v 1.15 2016/04/11 19:01:40 ryoon Exp $

DISTNAME=	qtquickcontrols-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtquickcontrols-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 module for QuickControls

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
