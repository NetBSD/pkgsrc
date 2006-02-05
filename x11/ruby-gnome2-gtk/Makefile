# $NetBSD: Makefile,v 1.4 2006/02/05 23:11:43 joerg Exp $
#

PKGNAME=		ruby-gnome2-gtk-${VERSION}
PKGREVISION=		3
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
