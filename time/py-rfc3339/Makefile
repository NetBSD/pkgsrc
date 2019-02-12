# $NetBSD: Makefile,v 1.3 2019/02/12 08:34:48 adam Exp $

DISTNAME=	pyRFC3339-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyRFC3339/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kurtraschke/pyRFC3339
COMMENT=	Library for generating and parsing RFC 3339-compliant timestamps
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
