# $NetBSD: Makefile,v 1.1 2020/08/03 23:04:12 joerg Exp $

DISTNAME=	l18n-2018.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/l18n/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tkhyn/l18n
COMMENT=	Translations for pytz names
LICENSE=	mit

USE_LANGUAGES=	# none

TEST_DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
