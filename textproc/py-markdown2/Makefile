# $NetBSD: Makefile,v 1.19 2022/01/04 20:54:59 wiz Exp $

DISTNAME=	markdown2-2.3.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/markdown2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trentm/python-markdown2
COMMENT=	Fast and complete Python implementation of Markdown
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON=	lib/markdown2.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} markdown2 markdown2-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/test && ${PYTHONBIN} test.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
