# $NetBSD: Makefile,v 1.4 2026/01/30 09:16:23 wiz Exp $

DISTNAME=	strict-rfc3339-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/strict-rfc3339/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.danielrichman.co.uk/libraries/strict-rfc3339.html
COMMENT=	Strict, simple, lightweight RFC3339 functions
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
#DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
