# $NetBSD: Makefile,v 1.4 2008/02/20 11:29:01 xtraeme Exp $

DISTNAME=	gtksourceview-sharp-2.0-0.11
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://go-mono.com/sources/gtksourceview-sharp2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Gtk
COMMENT=	C\# Bindings to the GtkSourceView widget

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
