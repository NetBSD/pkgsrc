# $NetBSD: Makefile,v 1.7 2002/01/09 14:46:50 drochner Exp $
#

DISTNAME=	gtk+extra-0.99.17
CATEGORIES=	x11
MASTER_SITES=	http://gtkextra.sourceforge.net/src/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://gtkextra.sourceforge.net/
COMMENT=	useful set of GTK+ widgets for creating GUIs

DEPENDS+=	gtk+>=1.2.0:../../x11/gtk

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
