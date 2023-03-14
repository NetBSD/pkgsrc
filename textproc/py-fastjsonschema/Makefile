# $NetBSD: Makefile,v 1.3 2023/03/14 10:43:48 adam Exp $

DISTNAME=	fastjsonschema-2.16.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastjsonschema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seznam/python-fastjsonschema
COMMENT=	Fastest Python implementation of JSON schema
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
