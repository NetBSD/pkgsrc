# $NetBSD: Makefile,v 1.9 2022/11/14 13:25:07 wiz Exp $

DISTNAME=	http-parser-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=h/http-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benoitc/http-parser
COMMENT=	HTTP request/response parser
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

USE_LANGUAGES=	c

# 0.9.0 tarball is not compatible with python 3.11
# re-generate files with newer cython that supports python 3.11
post-extract:
	cd ${WRKSRC} && cythonize-${PYVERSSUFFIX} http_parser

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
