# $NetBSD: Makefile,v 1.24 2004/10/03 00:18:33 tv Exp $

DISTNAME=		gtk-engines-2.2.0
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		8
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+ version 2

CONFLICTS+=		gtk-engines-*

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_X11=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	gtk-engines-2.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
