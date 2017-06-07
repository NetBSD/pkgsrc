# $NetBSD: Makefile,v 1.1 2017/06/07 09:53:42 he Exp $
#

DISTNAME=	jxmlease-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jxmlease/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/jxmlease
COMMENT=	Module for converting XML to Python data structures
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
