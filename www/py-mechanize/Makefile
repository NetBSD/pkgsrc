# $NetBSD: Makefile,v 1.10 2012/10/28 06:31:01 asau Exp $
#

DISTNAME=	mechanize-0.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/m/mechanize/ \
		http://wwwsearch.sourceforge.net/mechanize/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wwwsearch.sourceforge.net/mechanize/
COMMENT=	Stateful programmatic web browsing in Python

USE_LANGUAGES=	# none

do-test:
	${RUN}cd ${WRKSRC}; ${PYTHONBIN} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
