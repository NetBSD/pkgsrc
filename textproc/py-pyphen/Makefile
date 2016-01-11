# $NetBSD: Makefile,v 1.3 2016/01/11 16:21:33 kleink Exp $

DISTNAME=	Pyphen-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pyphen/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://pyphen.org/
COMMENT=	Pure Python module to hyphenate text
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mpl-1.1

USE_LANGUAGES=	# empty

REPLACE_PYTHON=+setup.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
