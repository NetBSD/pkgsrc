# $NetBSD: Makefile,v 1.83 2018/11/14 22:22:40 kleink Exp $
#

DISTNAME=	gnome-desktop-sharp-2.26.0
PKGREVISION=	74
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-desktop-sharp/2.26/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/GtkSharp
COMMENT=	C\# bindings for the GNOME platform, Desktop part

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	gnomedesktop/gnome-desktop-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnomepanel/gnome-panel-sharp-2.24.pc.in
PKGCONFIG_OVERRIDE+=	gnomeprint/gnome-print-sharp-2.18.pc.in
PKGCONFIG_OVERRIDE+=	gtkhtml/gtkhtml-sharp-3.14.pc.in
PKGCONFIG_OVERRIDE+=	gtksourceview/gtksourceview2-sharp.pc.in
PKGCONFIG_OVERRIDE+=	nautilusburn/nautilusburn-sharp.pc.in
PKGCONFIG_OVERRIDE+=	rsvg/rsvg2-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	vte/vte-sharp-0.16.pc.in
PKGCONFIG_OVERRIDE+=	wnck/wnck-sharp-1.0.pc.in

SUBST_CLASSES=		pc
SUBST_STAGE.pc=		pre-configure
SUBST_FILES.pc=		${PKGCONFIG_OVERRIDE}
SUBST_SED.pc=		-e "s|\$${pcfiledir}/../..|@prefix@|g"
SUBST_MESSAGE.pc=	Fixing hardcoded paths.

BUILDLINK_API_DEPENDS.libwnck+=		libwnck>=2.26.0
.include "../../devel/libwnck/buildlink3.mk"
BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.22.2
.include "../../graphics/librsvg/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeprint+=	libgnomeprint>=2.18.0
.include "../../print/libgnomeprint/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeprintui+=	libgnomeprintui>=2.18.0
.include "../../print/libgnomeprintui/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkhtml314+=	gtkhtml314>=3.23.5
.include "../../www/gtkhtml314/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-panel+=	gnome-panel>=2.26.0
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-sharp+=	gtk-sharp>=2.12.2
.include "../../x11/gtk-sharp/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.2.2
.include "../../x11/gtksourceview2/buildlink3.mk"
BUILDLINK_API_DEPENDS.vte+=		vte>=0.16.14<0.32
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
