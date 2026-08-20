# $NetBSD: Makefile,v 1.6 2026/08/20 10:13:14 adam Exp $

DISTNAME=	urlobject-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/urlo/URLO/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=U/URLObject/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zacharyvoase/urlobject
COMMENT=	Utility class for manipulating URLs
LICENSE=	unlicense

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
