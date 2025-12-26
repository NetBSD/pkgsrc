# $NetBSD: Makefile,v 1.28 2025/12/26 12:00:13 adam Exp $

DISTNAME=	pyqt_builder-1.19.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqt_/qt-/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt-builder/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://pyqt-builder.readthedocs.io/
COMMENT=	PyQt-world build tool (sip extension)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
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
