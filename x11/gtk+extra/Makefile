# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 12:25:51 rh Exp $
#

DISTNAME=	gtk+extra-0.99.11
CATEGORIES=	x11
MASTER_SITES=	http://magnet.fsu.edu/~feiguin/gtk/src/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://magnet.fsu.edu/~feiguin/gtk/

DEPENDS+=	gtk+>=1.2.0:../../x11/gtk

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
