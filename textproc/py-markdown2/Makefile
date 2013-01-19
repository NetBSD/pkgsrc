# $NetBSD: Makefile,v 1.5 2013/01/19 10:35:05 obache Exp $
#

DISTNAME=	markdown2-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/m/markdown2/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/trentm/python-markdown2
COMMENT=	Fast and complete Python implementation of Markdown
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_SELF_CONFLICT=		yes

do-test:
	${RUN}cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
