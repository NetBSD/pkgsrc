# $NetBSD: Makefile,v 1.25 2022/01/05 15:41:25 wiz Exp $

DISTNAME=	Markdown-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markdown/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://Python-Markdown.github.io/
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} markdown_py markdown_py${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
