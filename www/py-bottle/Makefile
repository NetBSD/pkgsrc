# $NetBSD: Makefile,v 1.16 2023/03/06 09:29:03 adam Exp $

DISTNAME=	bottle-0.12.25
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
