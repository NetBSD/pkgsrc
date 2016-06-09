# $NetBSD: Makefile,v 1.15 2016/06/09 05:23:51 wiz Exp $

DISTNAME=	mechanize-0.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mechanize/} \
		http://wwwsearch.sourceforge.net/mechanize/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wwwsearch.sourceforge.net/mechanize/
COMMENT=	Stateful programmatic web browsing in Python

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.2.5

do-test:
	${RUN}cd ${WRKSRC}; ${PYTHONBIN} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
