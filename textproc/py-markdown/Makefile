# $NetBSD: Makefile,v 1.17 2018/01/05 15:20:58 adam Exp $

DISTNAME=	Markdown-2.6.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markdown/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://Python-Markdown.github.io/
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} markdown_py markdown_py${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run-tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
