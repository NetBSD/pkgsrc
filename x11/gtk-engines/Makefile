# $NetBSD: Makefile,v 1.27 2005/09/28 20:52:27 rillig Exp $

DISTNAME=		gtk-engines-0.12
PKGREVISION=		7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/0.12/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+

CONFLICTS+=		gtk2-engines-*

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_X11BASE=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
