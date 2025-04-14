# $NetBSD: Makefile,v 1.6 2025/04/14 13:08:21 adam Exp $

DISTNAME=	webencodings-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/webencodings/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/python-webencodings
COMMENT=	Character encoding for the web
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
