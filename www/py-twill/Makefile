# $NetBSD: Makefile,v 1.7 2016/08/28 15:48:37 wiz Exp $

DISTNAME=	twill-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twill/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://twill.idyll.org/
COMMENT=	Python package for the twill Web browsing language
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # setup fails for 1.8.0

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/twill-fork \
		${DESTDIR}${PREFIX}/bin/twill-fork${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/twill-sh \
		${DESTDIR}${PREFIX}/bin/twill-sh${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
