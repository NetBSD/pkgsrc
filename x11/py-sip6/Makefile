# $NetBSD: Makefile,v 1.17 2024/02/14 00:18:12 gdt Exp $

# Before updating sip, geography/qgis (as the most demanding sip user
# currently known) must be tested to build ok.  The 6.8.0 release of
# sip was very broken, and .0 releases of sip should be viewed with
# extreme caution and probably skipped.
DISTNAME=	sip-6.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/sip/sip6/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sip/}

MAINTAINER=	gdt@NetBSD.org
#MAINTAINER+=	rhialto@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/sip/
COMMENT=	Tool to create Python bindings for C++ libraries
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	c c++

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
