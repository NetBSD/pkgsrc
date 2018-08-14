# $NetBSD: Makefile,v 1.11 2018/08/14 15:23:51 leot Exp $

DISTNAME=	pendulum-2.0.3
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
.if "${PYPKGPREFIX}" == "py27" || "${PYPKGPREFIX}" == "py34"
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

#
# XXX: C Extensions code is only supported with Python 3
#
.if "${PYPKGPREFIX}" == "py27"
MAKE_ENV+=	PENDULUM_EXTENSIONS=0
.endif

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
