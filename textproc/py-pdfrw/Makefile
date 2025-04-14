# $NetBSD: Makefile,v 1.9 2025/04/14 12:39:21 adam Exp $

DISTNAME=	pdfrw-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdfrw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pmaupin/pdfrw
COMMENT=	PDF file reader/writer pure Python library
LICENSE=	mit AND modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
