# $NetBSD: Makefile,v 1.4 2024/04/30 09:35:19 wiz Exp $

DISTNAME=	relativetimebuilder-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/relativetimebuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/nielsenb/relativetimebuilder
COMMENT=	Dateutil relativedeltas for calendar precision with aniso8601
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aniso8601>=9.0.0:../../time/py-aniso8601
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.3:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
