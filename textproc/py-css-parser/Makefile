# $NetBSD: Makefile,v 1.4 2022/02/03 09:10:12 adam Exp $

DISTNAME=	css-parser-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/css-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ebook-utils/css-parser
COMMENT=	Cascading Style Sheets parser and library for Python
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/css_parser/*.py
REPLACE_PYTHON+=	src/css_parser/scripts/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
