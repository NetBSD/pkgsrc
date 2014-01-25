# $NetBSD: Makefile,v 1.26 2014/01/25 10:30:26 wiz Exp $

DISTNAME=	pytz-2013.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pytz/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://pytz.sourceforge.net/
COMMENT=	World timezone definitions, modern and historical
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON=	pytz/tzfile.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
