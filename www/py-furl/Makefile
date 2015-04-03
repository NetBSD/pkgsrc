# $NetBSD: Makefile,v 1.8 2015/04/03 16:29:17 rodent Exp $

DISTNAME=	furl-0.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/f/furl/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/gruns/furl
COMMENT=	URL manipulation made simple
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-orderedmultidict>=0.7.1:../../databases/py-orderedmultidict

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	26 # via py-orderedmultidict

post-install:
	chmod -x ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
