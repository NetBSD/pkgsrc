# $NetBSD: Makefile,v 1.2 2024/11/11 07:29:13 wiz Exp $

DISTNAME=	strict-rfc3339-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/strict-rfc3339/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.danielrichman.co.uk/libraries/strict-rfc3339.html
COMMENT=	Strict, simple, lightweight RFC3339 functions
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
#DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
