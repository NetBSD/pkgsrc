# $NetBSD: Makefile,v 1.3 2001/02/17 17:06:27 wiz Exp $
#

DISTNAME=	gtk+extra-0.99.12
CATEGORIES=	x11
MASTER_SITES=	http://gtkextra.sourceforge.net/src/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://magnet.fsu.edu/~feiguin/gtk/
COMMENT=	useful set of GTK+ widgets for creating GUIs

DEPENDS+=	gtk+>=1.2.0:../../x11/gtk

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
