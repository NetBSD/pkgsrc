# $NetBSD: Makefile,v 1.1 2025/07/22 11:07:23 wiz Exp $

DISTNAME=	et_xmlfile-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/et_xmlfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://foss.heptapod.net/openpyxl/et_xmlfile
COMMENT=	Implementation of lxml.xmlfile for the standard library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
