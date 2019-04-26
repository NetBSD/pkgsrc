# $NetBSD: Makefile,v 1.16 2019/04/26 13:14:18 maya Exp $

DISTNAME=		wxRemind-0.6.18
PKGREVISION=		5
CATEGORIES=		time
MASTER_SITES=		http://www.duke.edu/~dgraham/wxRemind/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.duke.edu/~dgraham/wxRemind/
COMMENT=		Graphical front-end to Remind

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6.1:../../x11/py-wxWidgets

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-wxWidgets

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
