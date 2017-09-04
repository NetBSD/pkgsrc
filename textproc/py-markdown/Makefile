# $NetBSD: Makefile,v 1.15 2017/09/04 18:08:28 wiz Exp $

DISTNAME=	Markdown-2.6.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markdown/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/Markdown
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/bin/markdown_py ${WRKSRC}/bin/markdown_py${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run-tests.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
