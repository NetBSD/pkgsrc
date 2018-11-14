# $NetBSD: Makefile,v 1.12 2018/11/14 10:31:58 adam Exp $

DISTNAME=	pendulum-2.0.4
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
.if ${_PYTHON_VERSION} == 27 || ${_PYTHON_VERSION} == 34
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

# XXX: C Extensions code is only supported with Python 3
.if ${_PYTHON_VERSION} == 27
MAKE_ENV+=	PENDULUM_EXTENSIONS=0
.endif

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
