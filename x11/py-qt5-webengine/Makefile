# $NetBSD: Makefile,v 1.24 2026/01/07 08:49:41 wiz Exp $

DISTNAME=	PyQtWebEngine-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-qt5-webengine-5.15.7
PKGREVISION=	2
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQtWebEngine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/pyqtwebengine/
COMMENT=	Python module for QtWebEngine (Chromium-based)
LICENSE=	gnu-gpl-v3

WHEEL_NAME=	${DISTNAME:tl}

TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6-[0-9]*:../../x11/py-sip6
TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder-[0-9]*:../../x11/py-qt-builder
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5

USE_LANGUAGES=	c c++

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../lang/python/wheel.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
