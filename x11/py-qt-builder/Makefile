# $NetBSD: Makefile,v 1.16 2024/06/28 17:19:26 wiz Exp $

DISTNAME=	pyqt_builder-1.16.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqt_/qt-/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt-builder/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/pyqt-builder/
COMMENT=	PyQt-world build tool (sip extension)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.3:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-sip6>=6.7:../../x11/py-sip6

WHEEL_NAME=	${DISTNAME:S/pyqt_/PyQt_/:C/-([^0-9])/_\1/g}

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/${PYSITELIB}/pyqtbuild/bundle/dlls
.for bin in pyqt-bundle pyqt-qt-wheel
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
