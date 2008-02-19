# $NetBSD: Makefile,v 1.3 2008/02/19 13:57:39 xtraeme Exp $

DISTNAME=	gtksourceview-sharp-2.0-0.11
CATEGORIES=	x11
MASTER_SITES=	http://go-mono.com/sources/gtksourceview-sharp2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Gtk
COMMENT=	C\# Bindings to the GtkSourceView widget

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

BUILDLINK_API_DEPENDS.gtksourceview+=	gtksourceview>=2.1.2

SUBST_CLASSES=	f
SUBST_STAGE.f=	post-patch
SUBST_FILES.f=	configure
SUBST_SED.f=	-e "s|gtksourceview-1.0|gtksourceview-2.0|g"

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
