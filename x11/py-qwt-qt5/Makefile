# $NetBSD: Makefile,v 1.26 2024/05/29 16:35:09 adam Exp $

DISTNAME=	pyqt-qwt-1.02.02
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqt-qwt/qwt-qt5/}
PKGREVISION=	13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=GauiStori/}
GITHUB_PROJECT=	PyQt-Qwt
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GauiStori/PyQt-Qwt
COMMENT=	Python PyQt wrapper for Qwt6
LICENSE=	gnu-lgpl-v2.1 # with exception (Qwt License)

TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6-[0-9]*:../../x11/py-sip6
TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder-[0-9]*:../../x11/py-qt-builder
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-sip-qt5>=12:../../x11/py-sip-qt5

PYTHON_VERSIONS_INCOMPATIBLE=	27

WHEEL_NAME=	PyQt_Qwt-${PKGVERSION_NOREV}

USE_LANGUAGES=	c++

PLIST_SUBST+=	PYTHON_VERSION=${_PYTHON_VERSION}

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/PyQt5/Qwt.cpython-${PYTHON_VERSION}.so \
		${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt5/Qwt.cpython-${PYTHON_VERSION}.so
.endif

.include "../../lang/python/wheel.mk"
.include "../../x11/qwt6-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
