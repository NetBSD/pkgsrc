# $NetBSD: Makefile,v 1.10 2025/04/14 11:46:26 adam Exp $

DISTNAME=	tempita-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/t/T/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/Tempita/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TurboGears/tempita
COMMENT=	Small Python templating language
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
