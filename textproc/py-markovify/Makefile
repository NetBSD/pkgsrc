# $NetBSD: Makefile,v 1.11 2022/04/12 18:27:35 nikita Exp $

DISTNAME=	markovify-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/markovify/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/jsvine/markovify
COMMENT=	Simple and extensible Markov chain generator
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
