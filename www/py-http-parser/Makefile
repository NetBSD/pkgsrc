# $NetBSD: Makefile,v 1.2 2014/01/27 18:41:15 wiz Exp $

DISTNAME=	http-parser-0.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/h/http-parser/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/benoitc/http-parser
COMMENT=	HTTP request/response parser
LICENSE=	mit

USE_LANGUAGES=	c
EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
