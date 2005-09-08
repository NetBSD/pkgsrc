# $NetBSD: Makefile,v 1.1.1.1 2005/09/08 10:21:20 bouyer Exp $
#

DISTNAME=	gtk+extra-2.1.1
PKGNAME=	${DISTNAME:S/gtk/gtk2/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scigraphica/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://gtkextra.sourceforge.net/
COMMENT=	Useful set of GTK+ widgets for creating GUIs

USE_X11BASE=		YES
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
