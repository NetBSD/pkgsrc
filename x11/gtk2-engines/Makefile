# $NetBSD: Makefile,v 1.36 2006/01/24 07:32:53 wiz Exp $

DISTNAME=		gtk-engines-2.6.6
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+ version 2

CONFLICTS+=		gtk-engines-[0-9]*
CONFLICTS+=		gtk2-engines-clearlooks-[0-9]*
CONFLICTS+=		gtk2-engines-industrial-[0-9]*
CONFLICTS+=		gnome-themes-extras<0.8

BUILDLINK_DEPENDS.gtk2+=	gtk2+>=2.6.4

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_DIRS+=		theme-1.1 xdg-1.1
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	gtk-engines-2.pc.in

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
