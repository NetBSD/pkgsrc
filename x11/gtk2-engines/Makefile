# $NetBSD: Makefile,v 1.22 2004/04/05 13:27:00 tron Exp $

DISTNAME=		gtk-engines-2.2.0
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+ version 2

DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

CONFLICTS+=		gtk-engines-*

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	gtk-engines-2.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
