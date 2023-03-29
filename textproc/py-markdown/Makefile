# $NetBSD: Makefile,v 1.28 2023/03/29 09:34:14 wiz Exp $

DISTNAME=	Markdown-3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markdown/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://Python-Markdown.github.io/
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.4.0:../../devel/py-importlib-metadata
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} markdown_py markdown_py${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
