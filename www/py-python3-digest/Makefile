# $NetBSD: Makefile,v 1.8 2017/09/16 19:27:24 wiz Exp $

DISTNAME=	python3-digest-1.8b4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python3/python/}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python3-digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/akoha/python-digest/
COMMENT=	Python library to aid in implementing HTTP Digest Authentication
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	chmod -R a+rX ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
