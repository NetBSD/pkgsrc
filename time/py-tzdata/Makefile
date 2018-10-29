# $NetBSD: Makefile,v 1.7 2018/10/29 11:11:27 adam Exp $

DISTNAME=	pytzdata-2018.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytzdata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/pytzdata
COMMENT=	Timezone database for Python
LICENSE=	mit

USE_LANGUAGES=	# none

#.include "../../lang/python/egg.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
