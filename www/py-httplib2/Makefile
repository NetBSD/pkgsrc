# $NetBSD: Makefile,v 1.16 2019/08/11 18:05:54 adam Exp $

DISTNAME=	httplib2-0.13.1
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
