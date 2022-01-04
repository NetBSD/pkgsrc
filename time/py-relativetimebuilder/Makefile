# $NetBSD: Makefile,v 1.2 2022/01/04 20:55:13 wiz Exp $

DISTNAME=	relativetimebuilder-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/relativetimebuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/nielsenb/relativetimebuilder
COMMENT=	Dateutil relativedeltas for calendar precision with aniso8601
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-aniso8601>=5.0.0:../../time/py-aniso8601
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.3:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
