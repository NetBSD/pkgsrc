# $NetBSD: Makefile,v 1.13 2019/02/17 08:59:28 adam Exp $

DISTNAME=	httplib2-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httplib2/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/httplib2/httplib2
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

USE_LANGUAGES=	# none

# tests not included
do-test:
	${DO_NADA}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
