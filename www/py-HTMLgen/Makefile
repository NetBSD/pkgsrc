# $NetBSD: Makefile,v 1.1.1.1 2002/02/05 19:44:53 drochner Exp $
#

DISTNAME=	HTMLgen
PKGNAME=	${PYPKGPREFIX}-HTMLgen-2.2.2
CATEGORIES=	www
MASTER_SITES=	http://starship.python.net/crew/friedrich/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	py-HTMLgen-2.2.2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/friedrich/HTMLgen/html/main.html
COMMENT=	class library for the generation of HTML documents

NO_BUILD=	yes
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN}
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
