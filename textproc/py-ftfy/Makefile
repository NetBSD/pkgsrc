# $NetBSD: Makefile,v 1.1 2015/04/02 22:36:59 rodent Exp $

DISTNAME=	ftfy-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	https://pypi.python.org/packages/source/f/ftfy/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/LuminosoInsight/python-ftfy
COMMENT=	Fixes some problems with Unicode text after the fact
LICENSE=	mit

USE_LANGUAGES=	# none

PLIST_SUBST=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/ftfy \
		${DESTDIR}${PREFIX}/bin/ftfy${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
