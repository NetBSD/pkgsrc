# $NetBSD: Makefile,v 1.8 2002/09/22 10:30:00 jlam Exp $
#

DISTNAME=	gtk+extra-0.99.17
CATEGORIES=	x11
MASTER_SITES=	http://gtkextra.sourceforge.net/src/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://gtkextra.sourceforge.net/
COMMENT=	useful set of GTK+ widgets for creating GUIs

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
