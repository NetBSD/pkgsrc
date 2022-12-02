# $NetBSD: Makefile,v 1.5 2022/12/02 15:26:43 wiz Exp $

DISTNAME=	PyQt-builder-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-qt-builder-1.14.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt-builder/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/pyqt-builder/
COMMENT=	Tool to create Python bindings for C++ libraries using Qt
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sip6>=6.7:../../x11/py-sip6

DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c c++

post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/pyqtbuild/bundle && rm -r dlls
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} pyqt-bundle pyqt-bundle-${PYVERSSUFFIX} && \
		${MV} pyqt-qt-wheel pyqt-qt-wheel-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
