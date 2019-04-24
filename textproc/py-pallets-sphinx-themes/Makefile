# $NetBSD: Makefile,v 1.1 2019/04/24 15:52:31 adam Exp $

DISTNAME=	Pallets-Sphinx-Themes-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pallets-Sphinx-Themes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets/pallets-sphinx-themes
COMMENT=	Sphinx themes for Pallets and related projects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
