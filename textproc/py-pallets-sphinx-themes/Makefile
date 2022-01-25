# $NetBSD: Makefile,v 1.7 2022/01/25 09:05:11 wiz Exp $

DISTNAME=	Pallets-Sphinx-Themes-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pallets-Sphinx-Themes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets/pallets-sphinx-themes
COMMENT=	Sphinx themes for Pallets and related projects
LICENSE=	modified-bsd

PYTHON_VERSIONED_DEPENDENCIES+=	sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
PYTHON_VERSIONED_DEPENDENCIES+= importlib-metadata
.endif

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
