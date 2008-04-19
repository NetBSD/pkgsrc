# $NetBSD: Makefile,v 1.2 2008/04/19 19:02:36 kefren Exp $
#

DISTNAME=		gtk-sharp-2.10.4
CATEGORIES=		x11
MASTER_SITES=		http://go-mono.com/sources/gtk-sharp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mono-project.com/GtkSharp
COMMENT=		C\# bindings for GTK

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake perl:run
GNU_CONFIGURE=		yes

MAKE_JOBS_SAFE=		no

REPLACE_PERL+=		parser/*.pl
PKGCONFIG_OVERRIDE+=	gtk/gtk-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtkdotnet/gtk-dotnet-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glib/glib-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	parser/gapi-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glade/glade-sharp-2.0.pc.in

SUBST_CLASSES+=		relprefix
SUBST_MESSAGE.relprefix=Replacing relative prefix in pkg-config files.
SUBST_STAGE.relprefix=	post-patch
SUBST_FILES.relprefix=	${PKGCONFIG_OVERRIDE}
SUBST_SED.relprefix=	-e 's|$${pcfiledir}/../..|@prefix@|g'

.include "../../devel/libglade/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../lang/monodoc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
