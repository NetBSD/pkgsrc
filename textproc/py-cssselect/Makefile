# $NetBSD: Makefile,v 1.12 2026/02/09 13:45:11 adam Exp $

DISTNAME=	cssselect-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cssselect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.python.org/cssselect/
COMMENT=	Parses CSS3 Selectors and translates them to XPath 1.0
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27.0:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
