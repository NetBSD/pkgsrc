# $NetBSD: Makefile,v 1.21 2004/04/05 13:27:00 tron Exp $

DISTNAME=		gtk-engines-0.12
PKGREVISION=		6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/0.12/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+

DEPENDS+=		xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

CONFLICTS+=		gtk2-engines-*

GNU_CONFIGURE=		# defined
USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
SHLIBTOOL_OVERRIDE=	libtool

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
