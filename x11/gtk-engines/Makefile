# $NetBSD: Makefile,v 1.25 2004/10/03 00:18:33 tv Exp $

DISTNAME=		gtk-engines-0.12
PKGREVISION=		7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/0.12/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+

CONFLICTS+=		gtk2-engines-*

GNU_CONFIGURE=		# defined
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
SHLIBTOOL_OVERRIDE=	libtool

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
