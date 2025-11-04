# $NetBSD: Makefile,v 1.19 2025/11/04 11:54:51 adam Exp $

DISTNAME=	webcolors-25.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/webcolors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ubernostrum/webcolors
COMMENT=	Library for working with color specifications for HTML and CSS
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
