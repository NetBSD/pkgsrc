# $NetBSD: Makefile,v 1.3 2020/08/03 13:51:29 adam Exp $

DISTNAME=	feedgenerator-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/feedgenerator/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/getpelican/feedgenerator
COMMENT=	Standalone version of django.utils.feedgenerator, compatible with Py3k
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
