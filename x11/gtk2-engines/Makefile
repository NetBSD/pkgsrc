# $NetBSD: Makefile,v 1.27 2005/01/13 19:51:19 jmmv Exp $

DISTNAME=		gtk-engines-2.6.0
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+ version 2

CONFLICTS+=		gtk-engines-*
CONFLICTS+=		gtk2-engines-industrial-*
CONFLICTS+=		gnome-themes-extras<0.8

BUILDLINK_DEPENDS.gtk2+=	gtk2+>=2.6.0nb2

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		theme-1.0 xdg-1.1
USE_X11=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	gtk-engines-2.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
