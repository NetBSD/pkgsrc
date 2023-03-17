# $NetBSD: Makefile,v 1.5 2023/03/17 13:50:41 adam Exp $

DISTNAME=	sip-6.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/sip/sip6/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sip/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/sip/
COMMENT=	Tool to create Python bindings for C++ libraries
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-ply>=0:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml

USE_LANGUAGES=	c c++

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
