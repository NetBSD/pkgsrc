# $NetBSD: Makefile,v 1.1 2012/08/15 09:27:34 obache Exp $
#

DISTNAME=	markdown2-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/m/markdown2/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/trentm/python-markdown2
COMMENT=	Fast and complete Python implementation of Markdown
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X=	yes

do-test:
	${RUN}cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
