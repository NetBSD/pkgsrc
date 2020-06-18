# $NetBSD: Makefile,v 1.6 2020/06/18 12:26:24 adam Exp $

DISTNAME=	markovify-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/markovify/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/jsvine/markovify
COMMENT=	Simple and extensible Markov chain generator
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
