# $NetBSD: Makefile,v 1.2 2001/01/15 12:46:01 drochner Exp $
#

DISTNAME=	gtk+extra-0.99.12
CATEGORIES=	x11
MASTER_SITES=	http://gtkextra.sourceforge.net/src/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://magnet.fsu.edu/~feiguin/gtk/

DEPENDS+=	gtk+>=1.2.0:../../x11/gtk

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
