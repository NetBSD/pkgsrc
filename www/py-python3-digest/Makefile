# $NetBSD: Makefile,v 1.5 2015/12/10 02:57:34 joerg Exp $

DISTNAME=	python3-digest-1.8b4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python3/python/}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/p/python3-digest/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/akoha/python-digest/
COMMENT=	Python library to aid in implementing HTTP Digest Authentication
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	chmod -R a+rX ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
