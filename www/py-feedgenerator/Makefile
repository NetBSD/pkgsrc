# $NetBSD: Makefile,v 1.2 2017/02/03 09:47:12 nils Exp $

DISTNAME=		feedgenerator-1.9
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_PYPI:=f/feedgenerator/}

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://github.com/getpelican/feedgenerator
COMMENT=		Standalone version of django.utils.feedgenerator, compatible with Py3k
LICENSE=		modified-bsd

DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
