# $NetBSD: Makefile,v 1.76.2.1 2012/10/03 12:09:52 spz Exp $

DISTNAME=		gtk-engines-2.20.2
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		9
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/2.20/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+ version 2
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		gtk-engines-[0-9]*
CONFLICTS+=		gtk2-engines-clearlooks-[0-9]*
CONFLICTS+=		gtk2-engines-industrial-[0-9]*
CONFLICTS+=		gnome-themes-extras<0.8

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0

USE_TOOLS+=		gmake intltool pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--enable-animation

PKGCONFIG_OVERRIDE=	gtk-engines-2.pc.in

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
