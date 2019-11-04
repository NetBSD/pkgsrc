# $NetBSD: Makefile,v 1.5 2019/11/04 22:10:12 rillig Exp $

DISTNAME=	python-cloudfiles-1.7.11
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-cloudfiles/}

PYTHON_VERSIONS_ACCEPTED=	27

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/ncw/python-cloudfiles/
COMMENT=	CloudFiles client library for Python
LICENSE=	mit

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
