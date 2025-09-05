# $NetBSD: Makefile,v 1.43 2025/09/05 05:32:53 adam Exp $

DISTNAME=	markdown-3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markdown/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://Python-Markdown.github.io/
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.4.0:../../devel/py-importlib-metadata
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} markdown_py markdown_py${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
