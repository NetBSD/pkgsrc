# $NetBSD: Makefile,v 1.7 2024/11/11 07:29:14 wiz Exp $

DISTNAME=	types-python-dateutil-2.9.0.20241003
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-python-dateutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for python-dateutil
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
