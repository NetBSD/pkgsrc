# $NetBSD: Makefile,v 1.1.1.1 2008/04/27 23:12:54 wiz Exp $
#

DISTNAME=	gnome-desktop-sharp-2.20.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-desktop-sharp/2.20/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/GtkSharp
COMMENT=	C\# bindings for the GNOME platform, Desktop part

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	gnomedesktop/gnome-desktop-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtkhtml/gtkhtml-sharp-3.14.pc.in
PKGCONFIG_OVERRIDE+=	gtksourceview/gtksourceview2-sharp.pc.in
PKGCONFIG_OVERRIDE+=	nautilusburn/nautilusburn-sharp.pc.in
PKGCONFIG_OVERRIDE+=	rsvg/rsvg2-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	vte/vte-sharp-0.16.pc.in
PKGCONFIG_OVERRIDE+=	wnck/wnck-sharp-1.0.pc.in

SUBST_CLASSES=		pc
SUBST_STAGE.pc=		post-patch
SUBST_FILES.pc=		${PKGCONFIG_OVERRIDE}
SUBST_SED.pc=		-e "s|\$${pcfiledir}/../..|@prefix@|g"
SUBST_MESSAGE.pc=	Fixing hardcoded paths.

.include "../../lang/mono/buildlink3.mk"
.include "../../lang/monodoc/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.18.2
.include "../../graphics/librsvg/buildlink3.mk"
# XXX: needs >=2.20.0, not yet in pkgsrc
#BUILDLINK_API_DEPENDS.nautilus-cd-burner+=	nautilus-cd-burner>=2.20.0
#.include "../../sysutils/nautilus-cd-burner/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkhtml314+=	gtkhtml314>=3.16.0
.include "../../www/gtkhtml314/buildlink3.mk"
BUILDLINK_API_DEPENDS.vte+=	vte>=0.16.9
.include "../../x11/vte/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-sharp+=	gnome-sharp>=2.20.0
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
