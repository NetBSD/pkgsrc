# $NetBSD: Makefile,v 1.2 2017/06/07 10:23:16 he Exp $
#

DISTNAME=	jxmlease-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jxmlease/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/jxmlease
COMMENT=	Module for converting XML to Python data structures
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
