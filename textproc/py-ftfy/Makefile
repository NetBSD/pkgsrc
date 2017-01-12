# $NetBSD: Makefile,v 1.5 2017/01/12 00:45:43 rodent Exp $

DISTNAME=	ftfy-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=f/ftfy/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/LuminosoInsight/python-ftfy
COMMENT=	Fixes some problems with Unicode text after the fact
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/ftfy \
		${DESTDIR}${PREFIX}/bin/ftfy${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
