# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:44 wiz Exp $

DISTNAME=	Routes-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=R/Routes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/Routes
COMMENT=	Python re-implementation of the Rails routes system for mapping URLs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-repoze.lru-[0-9]*:../../devel/py-repoze.lru

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
