# $NetBSD: Makefile,v 1.12 2013/07/05 23:35:35 rodent Exp $
#

DISTNAME=		web.py-0.37
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		www python
MASTER_SITES=	http://webpy.org/static/

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://webpy.org/
COMMENT=		Simple, public domain web publishing system
LICENSE=		public-domain

USE_LANGUAGES=		#none

REPLACE_PYTHON+=	web/__init__.py web/utils.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
