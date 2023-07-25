# $NetBSD: Makefile,v 1.8 2023/07/25 08:25:02 adam Exp $

DISTNAME=	sip-6.7.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/sip/sip6/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sip/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/sip/
COMMENT=	Tool to create Python bindings for C++ libraries
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	c c++

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
