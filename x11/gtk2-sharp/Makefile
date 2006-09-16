# $NetBSD: Makefile,v 1.2 2006/09/16 12:20:41 jmmv Exp $
#

DISTNAME=		gtk-sharp-2.8.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://go-mono.com/sources/gtk-sharp-2.8/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gtk-sharp.sourceforge.net/
COMMENT=		C# bindings for GTK

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	art/art-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gconf/GConf/gconf-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glade/glade-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glib/glib-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome/gnome-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnomevfs/gnome-vfs-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk/gtk-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtkdotnet/gtk-dotnet-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtkhtml/gtkhtml-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	parser/gapi-2.0.pc.in
PKGCONFIG_OVERRIDE+=	rsvg/rsvg-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	vte/vte-sharp-2.0.pc.in

post-patch: substpcprefix
# replace relative prefix in pkgconfig files
substpcprefix:
.for f in ${PKGCONFIG_OVERRIDE}
	(cd ${WRKSRC}; \
	 ${SED} 's|$${pcfiledir}/../..|@prefix@|g' <$f >$f.tmp; \
	 ${MV} $f.tmp $f \
	)
.endfor

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../www/gtkhtml38/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
