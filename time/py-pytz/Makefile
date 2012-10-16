# $NetBSD: Makefile,v 1.18 2012/10/16 06:48:16 wiz Exp $
#

DISTNAME=	pytz-2012f
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
