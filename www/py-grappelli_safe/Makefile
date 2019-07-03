# $NetBSD: Makefile,v 1.3 2019/07/03 19:55:56 adam Exp $

DISTNAME=	grappelli_safe-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grappelli_safe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stephenmcd/grappelli-safe
COMMENT=	Permanent fork of Grapelli admin skin for Mezzanine
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
