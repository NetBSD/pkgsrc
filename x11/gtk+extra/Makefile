# $NetBSD: Makefile,v 1.12 2003/07/21 17:38:28 martti Exp $
#

DISTNAME=	gtk+extra-0.99.17
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://gtkextra.sourceforge.net/src/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://gtkextra.sourceforge.net/
COMMENT=	Useful set of GTK+ widgets for creating GUIs

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
