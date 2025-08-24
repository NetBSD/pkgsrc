# $NetBSD: Makefile,v 1.9 2025/08/24 16:13:53 wiz Exp $

DISTNAME=	pyrfc3339-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyRFC3339/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kurtraschke/pyRFC3339
COMMENT=	Library for generating and parsing RFC 3339-compliant timestamps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
