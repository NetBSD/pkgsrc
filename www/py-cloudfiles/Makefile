# $NetBSD: Makefile,v 1.3 2019/04/26 13:14:20 maya Exp $

DISTNAME=	python-cloudfiles-1.7.11
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-cloudfiles/}

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/ncw/python-cloudfiles/
COMMENT=	CloudFiles client library for Python
LICENSE=	mit

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
