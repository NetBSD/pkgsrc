# $NetBSD: Makefile,v 1.13 2017/09/16 19:27:24 wiz Exp $

DISTNAME=	furl-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=f/furl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gruns/furl
COMMENT=	URL manipulation made simple
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-six>=1.8.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-orderedmultidict>=0.7.6:../../databases/py-orderedmultidict

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
