# $NetBSD: Makefile,v 1.1 2019/02/14 11:57:20 wiz Exp $

DISTNAME=	css-parser-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/css-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cthedot.de/cssutils/
COMMENT=	Cascading Style Sheets parser and library for Python
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/css_parser/*.py src/css_parser/scripts/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
