# $NetBSD: Makefile,v 1.6 2004/07/22 09:16:00 recht Exp $
#

DISTNAME=	HTMLgen
PKGNAME=	${PYPKGPREFIX}-HTMLgen-2.2.2
CATEGORIES=	www python
MASTER_SITES=	http://starship.python.net/crew/friedrich/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	py-HTMLgen-2.2.2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/friedrich/HTMLgen/html/main.html
COMMENT=	Class library for the generation of HTML documents

NO_BUILD=	yes
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN}
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
