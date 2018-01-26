# $NetBSD: Makefile,v 1.1 2018/01/26 14:24:29 triaxx Exp $

DISTNAME=	python-cloudfiles-1.7.11
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-cloudfiles/}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/ncw/python-cloudfiles/
COMMENT=	CloudFiles client library for Python
LICENSE=	mit

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
