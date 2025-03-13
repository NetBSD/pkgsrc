# $NetBSD: Makefile,v 1.10 2025/03/13 15:19:52 adam Exp $

DISTNAME=	cssselect-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cssselect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.python.org/cssselect/
COMMENT=	Parses CSS3 Selectors and translates them to XPath 1.0
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
