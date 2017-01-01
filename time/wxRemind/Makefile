# $NetBSD: Makefile,v 1.13 2017/01/01 14:44:02 wiz Exp $

DISTNAME=		wxRemind-0.6.18
PKGREVISION=		4
CATEGORIES=		time
MASTER_SITES=		http://www.duke.edu/~dgraham/wxRemind/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.duke.edu/~dgraham/wxRemind/
COMMENT=		Graphical front-end to Remind

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6.1:../../x11/py-wxWidgets

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-wxWidgets

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
