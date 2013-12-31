# $NetBSD: Makefile,v 1.1 2013/12/31 19:32:32 rodent Exp $

DISTNAME=	http-parser-0.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/h/http-parser/
FETCH_USING=	curl

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/benoitc/http-parser
COMMENT=	HTTP request/response parser
LICENSE=	mit

USE_LANGUAGES=	c
EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
