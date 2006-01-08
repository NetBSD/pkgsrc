# $NetBSD: Makefile,v 1.1.1.1 2006/01/08 03:47:23 minskim Exp $
#

PKGNAME=		ruby-gnome2-gtk-${VERSION}
COMMENT=		Ruby binding of GTK+-2.0.x
CATEGORIES=		x11

RUBY_EXTCONF_SUBDIRS=	gtk

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		ruby-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=		ruby-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf

USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ruby-gnome2-pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
