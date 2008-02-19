# $NetBSD: Makefile,v 1.1.1.1 2008/02/19 13:48:13 xtraeme Exp $
#

DISTNAME=	gnome-sharp-2.16.1
CATEGORIES=	x11
MASTER_SITES=	http://go-mono.com/sources/gnome-sharp2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/GtkSharp
COMMENT=	C\# bindings for the GNOME platform

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	art/art-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gconf/GConf/gconf-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gconf/GConf.PropertyEditors/gconf-sharp-peditors-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome/gnome-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnomevfs/gnome-vfs-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtkhtml/gtkhtml-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	rsvg/rsvg-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	vte/vte-sharp-2.0.pc.in

SUBST_CLASSES=		pc
SUBST_STAGE.pc=		post-patch
SUBST_FILES.pc=		${PKGCONFIG_OVERRIDE}
SUBST_SED.pc=		-e "s|$${pcfiledir}/../..|@prefix@|g"
SUBST_MESSAGE.pc=	Fixing hardcoded paths.

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../lang/monodoc/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/gtkhtml38/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
