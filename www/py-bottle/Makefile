# $NetBSD: Makefile,v 1.13 2020/11/12 09:02:10 adam Exp $

DISTNAME=	bottle-0.12.19
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
	${MV} bottle.py bottle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
