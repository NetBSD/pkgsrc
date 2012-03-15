# $NetBSD: Makefile,v 1.7 2012/03/15 11:53:41 obache Exp $
#

DISTNAME=		wxRemind-0.6.18
PKGREVISION=		4
CATEGORIES=		time
MASTER_SITES=		http://www.duke.edu/~dgraham/wxRemind/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.duke.edu/~dgraham/wxRemind/
COMMENT=		Graphical front-end to Remind

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6.1:../../x11/py-wxWidgets

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
