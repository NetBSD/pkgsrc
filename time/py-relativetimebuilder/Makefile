# $NetBSD: Makefile,v 1.9 2026/07/15 06:04:34 adam Exp $

DISTNAME=	relativetimebuilder-3.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/relativetimebuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/nielsenb-jf/relativetimebuilder
COMMENT=	Dateutil relativedeltas for calendar precision with aniso8601
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aniso8601>=9.0.0:../../time/py-aniso8601
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.3:../../time/py-dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
