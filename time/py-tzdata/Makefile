# $NetBSD: Makefile,v 1.23 2025/04/13 12:23:19 wiz Exp $

DISTNAME=	tzdata-2025.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tzdata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/tzdata
COMMENT=	Provider of IANA time zone data
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
