# $NetBSD: Makefile,v 1.23 2025/01/26 15:44:36 he Exp $

DISTNAME=	ujson-5.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/ujson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/esnme/ultrajson
COMMENT=	Ultra fast JSON encoder and decoder for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
