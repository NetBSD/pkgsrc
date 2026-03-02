# $NetBSD: Makefile,v 1.2 2026/03/02 11:48:44 adam Exp $

DISTNAME=	zope_dottedname-7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.dottedname/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.dottedname
COMMENT=	Resolve strings containing dotted names
LICENSE=	zpl-2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
