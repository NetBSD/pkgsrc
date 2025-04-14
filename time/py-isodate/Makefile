# $NetBSD: Makefile,v 1.9 2025/04/14 08:49:20 adam Exp $

DISTNAME=	isodate-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isodate/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://cheeseshop.python.org/pypi/isodate
COMMENT=	ISO 8601 date/time/duration parser and formatter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
