# $NetBSD: Makefile,v 1.11 2025/04/14 11:57:58 adam Exp $

DISTNAME=	cssselect-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cssselect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.python.org/cssselect/
COMMENT=	Parses CSS3 Selectors and translates them to XPath 1.0
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
