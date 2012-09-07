# $NetBSD: Makefile,v 1.18 2012/09/07 19:17:46 adam Exp $
#

DISTNAME=	gtk+extra-2.1.2
PKGNAME=	${DISTNAME:S/gtk/gtk2/}
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkextra/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://gtkextra.sourceforge.net/
COMMENT=	Useful set of GTK+ widgets for creating GUIs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=		YES
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gtkextra-2.0.pc.in

# avoid possibility of unwanted glib-genmarshal
post-extract:
	${TOUCH} ${WRKSRC}/gtkextra/gtkextra-marshal.c

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
