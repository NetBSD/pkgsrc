# $NetBSD: Makefile,v 1.12 2016/12/15 13:44:20 adam Exp $

DISTNAME=	Markdown-2.6.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markdown/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/Markdown
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/bin/markdown_py ${WRKSRC}/bin/markdown_py${PYVERSSUFFIX}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run-tests.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
