# $NetBSD: Makefile,v 1.10 2020/01/26 17:32:23 rillig Exp $

DISTNAME=	bottle-0.12.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bottle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bottlepy.org/docs/stable/
COMMENT=	Fast, simple and lightweight WSGI micro web-framework for Python
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} bottle.py bottle-${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
