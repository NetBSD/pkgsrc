# $NetBSD: Makefile,v 1.10 2009/02/16 19:44:28 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}
PY_PATCHPLIST=	yes

INSTALLATION_DIRS+=	${PYSITELIB}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
