# $NetBSD: Makefile,v 1.10 2002/03/13 17:37:57 fredb Exp $

DISTNAME=		gtk-engines-0.12
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gtk-engines/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

BUILDLINK_DEPENDS.gtk=	gtk+>=1.2.9

.include "../../x11/gtk/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
