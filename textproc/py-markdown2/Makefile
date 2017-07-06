# $NetBSD: Makefile,v 1.12 2017/07/06 07:43:33 adam Exp $

DISTNAME=	markdown2-2.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=m/markdown2/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trentm/python-markdown2
COMMENT=	Fast and complete Python implementation of Markdown
LICENSE=	mit

USE_LANGUAGES=		# none

REPLACE_PYTHON=		lib/markdown2.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} markdown2 markdown2-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
