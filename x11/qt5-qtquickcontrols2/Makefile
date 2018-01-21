# $NetBSD: Makefile,v 1.1 2018/01/21 04:17:28 markd Exp $

DISTNAME=	qtquickcontrols2-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtquickcontrols2-${QTVERSION}
COMMENT=	Next generation user interface controls based on Qt Quick

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../wip/qt5-qtbase/Makefile.common"

.include "../../wip/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
