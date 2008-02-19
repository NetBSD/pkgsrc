# $NetBSD: Makefile,v 1.10 2008/02/19 13:47:37 xtraeme Exp $
#

DISTNAME=		gtk-sharp-2.10.3
CATEGORIES=		x11
MASTER_SITES=		http://go-mono.com/sources/gtk-sharp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mono-project.com/GtkSharp
COMMENT=		C\# bindings for GTK

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

REPLACE_PERL+=		parser/*.pl
PKGCONFIG_OVERRIDE+=	gtk/gtk-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtkdotnet/gtk-dotnet-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glib/glib-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	parser/gapi-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glade/glade-sharp-2.0.pc.in

post-patch: substpcprefix
# replace relative prefix in pkgconfig files
substpcprefix:
.for f in ${PKGCONFIG_OVERRIDE}
	(cd ${WRKSRC}; \
	 ${SED} 's|$${pcfiledir}/../..|@prefix@|g' <$f >$f.tmp; \
	 ${MV} $f.tmp $f \
	)
.endfor

.include "../../devel/libglade/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../lang/monodoc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
