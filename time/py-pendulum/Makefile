# $NetBSD: Makefile,v 1.1 2017/09/29 21:18:49 joerg Exp $

DISTNAME=	pendulum-1.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python time
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pendulum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/pendulum
COMMENT=	Human-friendly date and time handling
LICENSE=	mit

DEPENDS+=		${PYPKGPREFIX}-tzdata-[0-9]*:../../time/py-tzdata
DEPENDS+=		${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal
DEPENDS+=		${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
