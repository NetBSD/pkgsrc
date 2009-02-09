# $NetBSD: Makefile,v 1.4 2009/02/09 22:56:27 joerg Exp $
#

DISTNAME=		wxRemind-0.6.18
PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		http://www.duke.edu/~dgraham/wxRemind/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.duke.edu/~dgraham/wxRemind/
COMMENT=		Graphical front-end to Remind

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6.1:../../x11/py-wxWidgets
DEPENDS+=		${PYPKGPREFIX}-setuptools>=0.6b1:../../devel/py-setuptools

PYTHON_VERSIONS_ACCEPTED=	25 24
PYDISTUTILSPKG=			YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
