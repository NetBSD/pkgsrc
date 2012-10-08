# $NetBSD: Makefile,v 1.4 2012/10/08 13:04:28 asau Exp $

DISTNAME=	parsedatetime-0.8.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code-bear.com/code/parsedatetime/
COMMENT=	Python module for parsing human-readable date/time text
LICENSE=	apache-2.0

.include "../../mk/bsd.prefs.mk"

post-extract:
	${FIND} ${WRKSRC} -name "._*" -type f -print | ${XARGS} ${RM} -f

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
