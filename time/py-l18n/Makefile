# $NetBSD: Makefile,v 1.4 2022/01/23 19:19:10 adam Exp $

DISTNAME=	l18n-2021.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/l18n/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tkhyn/l18n
COMMENT=	Translations for pytz names
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pytz>=2020.1:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
