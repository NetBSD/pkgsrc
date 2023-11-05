# $NetBSD: Makefile,v 1.10 2023/11/05 11:59:56 wiz Exp $

DISTNAME=	http-parser-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=h/http-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benoitc/http-parser
COMMENT=	HTTP request/response parser
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	c

# 0.9.0 tarball is not compatible with python 3.11
# re-generate files with newer cython that supports python 3.11
post-extract:
	cd ${WRKSRC} && cythonize-${PYVERSSUFFIX} http_parser

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
