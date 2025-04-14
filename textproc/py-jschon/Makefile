# $NetBSD: Makefile,v 1.4 2025/04/14 12:15:00 adam Exp $

DISTNAME=	jschon-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jschon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/marksparkza/jschon
COMMENT=	JSON toolkit for Python developers
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-rfc3986-[0-9]*:../../www/py-rfc3986

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
