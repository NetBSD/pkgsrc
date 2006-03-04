# $NetBSD: Makefile,v 1.9 2006/03/04 21:31:03 jlam Exp $
#

DISTNAME=	HTMLgen
PKGNAME=	${PYPKGPREFIX}-HTMLgen-2.2.2
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://starship.python.net/crew/friedrich/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	py-HTMLgen-2.2.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/friedrich/HTMLgen/html/main.html
COMMENT=	Class library for the generation of HTML documents

NO_BUILD=	yes
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
