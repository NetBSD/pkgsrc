# $NetBSD: Makefile,v 1.9.2.1 2007/12/18 09:27:09 ghen Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtk-${VERSION}
PKGREVISION=		2
COMMENT=		Ruby binding of GTK+-2.x
CATEGORIES=		x11

CONFLICTS+=		ruby-gnome2-gtk-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gtk

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf

USE_TOOLS+=		pkg-config
DISTINFO_FILE?=		${.CURDIR}/distinfo

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ruby-gnome2-pango/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
