# $NetBSD: Makefile,v 1.4 2022/01/04 20:55:24 wiz Exp $

DISTNAME=	feedgenerator-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
