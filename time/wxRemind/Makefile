# $NetBSD: Makefile,v 1.11 2015/12/05 21:26:03 adam Exp $

DISTNAME=		wxRemind-0.6.18
PKGREVISION=		4
CATEGORIES=		time
MASTER_SITES=		http://www.duke.edu/~dgraham/wxRemind/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.duke.edu/~dgraham/wxRemind/
COMMENT=		Graphical front-end to Remind

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6.1:../../x11/py-wxWidgets

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-wxWidgets

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
