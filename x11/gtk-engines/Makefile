# $NetBSD: Makefile,v 1.13 2003/01/10 08:46:53 jlam Exp $

DISTNAME=		gtk-engines-0.12
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/0.12/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+

GNU_CONFIGURE=		# defined
USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILDLINK_DEPENDS.gtk=	gtk+>=1.2.9

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
