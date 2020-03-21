# $NetBSD: Makefile,v 1.15 2020/03/21 12:54:50 adam Exp $

DISTNAME=	pendulum-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pendulum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/pendulum
COMMENT=	Human-friendly date and time handling
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.6.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-tzdata>=2018.3:../../time/py-tzdata

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-typing>=3.6:../../devel/py-typing
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
