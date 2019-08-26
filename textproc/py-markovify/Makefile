# $NetBSD: Makefile,v 1.1 2019/08/26 18:32:43 ng0 Exp $

DISTNAME=	markovify-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/markovify/}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://pypi.org/project/markovify
COMMENT=	Simple and extensible Markov chain generator
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
