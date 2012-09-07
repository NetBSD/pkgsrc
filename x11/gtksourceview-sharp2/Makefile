# $NetBSD: Makefile,v 1.31 2012/09/07 19:17:47 adam Exp $

DISTNAME=	gtksourceview-sharp-2.0-0.12
PKGNAME=	${DISTNAME:S/-2.0-/2-/}
PKGREVISION=	25
CATEGORIES=	x11
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gtksourceview-sharp2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Gtk
COMMENT=	C\# Bindings to the GtkSourceView widget

PKG_DESTDIR_SUPPORT=	user-destdir

PREV_PKGPATH=	x11/gtksourceview-sharp
SUPERSEDES=	gtksourceview-sharp-2.0-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

CONFLICTS=	gtksourceview-sharp-2.0-[0-9]*

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
