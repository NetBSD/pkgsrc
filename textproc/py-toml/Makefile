# $NetBSD: Makefile,v 1.9 2025/04/13 12:28:11 wiz Exp $

DISTNAME=	toml-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uiri/toml
COMMENT=	Python Library for Tom's Obvious, Minimal Language
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
