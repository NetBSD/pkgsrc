# $NetBSD: Makefile,v 1.16 2005/03/10 14:17:15 tv Exp $
#

DISTNAME=	gtk+extra-0.99.17
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://gtkextra.sourceforge.net/src/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://gtkextra.sourceforge.net/
COMMENT=	Useful set of GTK+ widgets for creating GUIs

USE_BUILDLINK3=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
