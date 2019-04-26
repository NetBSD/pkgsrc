# $NetBSD: Makefile,v 1.14 2019/04/26 13:14:22 maya Exp $

DISTNAME=	twill-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://twill.idyll.org/
COMMENT=	Python package for the twill Web browsing language
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # setup fails for 1.8.0

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/twill-fork \
		${DESTDIR}${PREFIX}/bin/twill-fork${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/twill-sh \
		${DESTDIR}${PREFIX}/bin/twill-sh${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
