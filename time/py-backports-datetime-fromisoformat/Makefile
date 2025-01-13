# $NetBSD: Makefile,v 1.5 2025/01/13 08:35:58 adam Exp $

DISTNAME=	backports_datetime_fromisoformat-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports-datetime-fromisoformat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/movermeyer/backports.datetime_fromisoformat
COMMENT=	Backport of Python 3.11's datetime.fromisoformat
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

PYTHON_VERSIONS_ACCEPTED=	310 # included in Python 3.11

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
