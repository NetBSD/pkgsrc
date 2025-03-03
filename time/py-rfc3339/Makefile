# $NetBSD: Makefile,v 1.7 2025/03/03 07:06:19 wiz Exp $

DISTNAME=	pyrfc3339-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyRFC3339/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kurtraschke/pyRFC3339
COMMENT=	Library for generating and parsing RFC 3339-compliant timestamps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
