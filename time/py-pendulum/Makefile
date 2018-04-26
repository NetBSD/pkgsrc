# $NetBSD: Makefile,v 1.8 2018/04/26 07:53:20 adam Exp $

DISTNAME=	pendulum-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pendulum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/pendulum
COMMENT=	Human-friendly date and time handling
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-tzdata-[0-9]*:../../time/py-tzdata
DEPENDS+=	${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
