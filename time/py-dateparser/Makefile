# $NetBSD: Makefile,v 1.1 2017/09/29 21:21:52 joerg Exp $

DISTNAME=	dateparser-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python time
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dateparser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapinghub/dateparser
COMMENT=	Date parsing library designed to parse dates from HTML pages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.10.12:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal

# XXX Test needs nose.parameterized

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
