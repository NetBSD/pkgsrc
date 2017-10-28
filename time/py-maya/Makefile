# $NetBSD: Makefile,v 1.2 2017/10/28 08:54:11 adam Exp $

DISTNAME=	maya-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/maya/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/maya
COMMENT=	Human-friendly date and time handling
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dateparser-[0-9]*:../../time/py-dateparser
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-pendulum-[0-9]*:../../time/py-pendulum
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.10.12:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
