# $NetBSD: Makefile,v 1.97 2023/11/14 14:03:09 wiz Exp $

DISTNAME=	gtk-sharp-2.12.45
PKGREVISION=	20
CATEGORIES=	x11
MASTER_SITES=	https://download.mono-project.com/sources/gtk-sharp212/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mono-project.com/GtkSharp
COMMENT=	C\# bindings for GTK
LICENSE=	gnu-lgpl-v2.1

PREV_PKGPATH=	x11/gtk2-sharp

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake perl:run
GNU_CONFIGURE=	yes

MAKE_JOBS_SAFE=	no

USE_PKGLOCALEDIR=	yes

REPLACE_PERL+=		parser/*.pl
PKGCONFIG_OVERRIDE+=	gtk/gtk-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtkdotnet/gtk-dotnet-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glib/glib-sharp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	parser/gapi-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glade/glade-sharp-2.0.pc.in

SUBST_CLASSES+=			relprefix
SUBST_MESSAGE.relprefix=	Replacing relative prefix in pkg-config files.
SUBST_STAGE.relprefix=		pre-configure
SUBST_FILES.relprefix=		${PKGCONFIG_OVERRIDE}
SUBST_SED.relprefix=		-e 's|$${pcfiledir}/../..|@prefix@|g'

.include "../../devel/libglade/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
