# $NetBSD: Makefile,v 1.19 2004/02/14 17:21:55 jlam Exp $

DISTNAME=		gtk-engines-0.12
PKGREVISION=		5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/0.12/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+

GNU_CONFIGURE=		# defined
USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
SHLIBTOOL_OVERRIDE=	libtool

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
