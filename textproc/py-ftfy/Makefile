# $NetBSD: Makefile,v 1.3 2016/08/28 15:48:35 wiz Exp $

DISTNAME=	ftfy-3.4.0
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
		${DESTDIR}${PREFIX}/bin/ftfy${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
