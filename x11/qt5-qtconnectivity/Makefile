# $NetBSD: Makefile,v 1.8 2020/03/08 16:48:30 wiz Exp $

DISTNAME=	qtconnectivity-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtconnectivity-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for connectivity framework

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
