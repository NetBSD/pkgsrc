# $NetBSD: Makefile,v 1.7 2011/11/25 13:29:43 obache Exp $
#

DISTNAME=	mechanize-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://wwwsearch.sourceforge.net/mechanize/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wwwsearch.sourceforge.net/mechanize/
COMMENT=	Stateful programmatic web browsing in Python

DEPENDS+=	${PYPKGPREFIX}-ClientForm>=0.2.6:../../www/py-ClientForm

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 26 25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
