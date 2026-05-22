# $NetBSD: Makefile,v 1.5 2026/05/22 08:25:05 adam Exp $

DISTNAME=	uritools-6.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uritools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tkem/uritools/
COMMENT=	URI parsing, classification and composition
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.2:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
