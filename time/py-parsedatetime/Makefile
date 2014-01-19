# $NetBSD: Makefile,v 1.5 2014/01/19 19:52:44 wiz Exp $

DISTNAME=	v1.1.2
PKGNAME=	${PYPKGPREFIX}-parsedatetime-${DISTNAME:S/v//}
CATEGORIES=	time python
MASTER_SITES=	https://github.com/bear/parsedatetime/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bear/parsedatetime
COMMENT=	Python module for parsing human-readable date/time text
LICENSE=	apache-2.0

DIST_SUBDIR=	py-parsedatetime
WRKSRC=		${WRKDIR}/parsedatetime-${DISTNAME:S/v//}
EGG_NAME=	parsedatetime-${DISTNAME:S/v//}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
