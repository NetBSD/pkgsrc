# $NetBSD: Makefile,v 1.6 2010/02/10 19:17:46 joerg Exp $
#

DISTNAME=		wxRemind-0.6.18
PKGREVISION=		3
CATEGORIES=		time
MASTER_SITES=		http://www.duke.edu/~dgraham/wxRemind/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.duke.edu/~dgraham/wxRemind/
COMMENT=		Graphical front-end to Remind

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6.1:../../x11/py-wxWidgets

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
