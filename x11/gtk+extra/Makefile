# $NetBSD: Makefile,v 1.19 2006/02/05 23:11:34 joerg Exp $
#

DISTNAME=	gtk+extra-0.99.17
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://gtkextra.sourceforge.net/src/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://gtkextra.sourceforge.net/
COMMENT=	Useful set of GTK+ widgets for creating GUIs

USE_X11BASE=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
