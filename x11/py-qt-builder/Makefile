# $NetBSD: Makefile,v 1.21 2025/01/19 19:34:04 wiz Exp $

DISTNAME=	pyqt_builder-1.17.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqt_/qt-/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt-builder/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://pyqt-builder.readthedocs.io/
COMMENT=	PyQt-world build tool (sip extension)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

WHEEL_NAME=	${DISTNAME:S/pyqt_/PyQt_/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.3:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-sip6>=6.7:../../x11/py-sip6

USE_LANGUAGES=	c c++

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/${PYSITELIB}/pyqtbuild/bundle/dlls
.for bin in pyqt-bundle pyqt-qt-wheel
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
