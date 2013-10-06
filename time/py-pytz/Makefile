# $NetBSD: Makefile,v 1.23 2013/10/06 16:39:39 wiz Exp $

DISTNAME=	pytz-2013.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pytz/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://pytz.sourceforge.net/
COMMENT=	World timezone definitions, modern and historical
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X=	yes

REPLACE_PYTHON=	pytz/tzfile.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
