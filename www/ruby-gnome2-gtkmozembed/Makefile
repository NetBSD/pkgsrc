# $NetBSD: Makefile,v 1.1 2008/09/17 00:21:50 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtkmozembed-${VERSION}
COMMENT=		Ruby binding of gtkmozembed
CATEGORIES=		www

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtkmozembed

DEPENDS+=               ${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
USE_TOOLS+=		pkg-config

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby-gnome2-gtkmozembed
.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/ruby-gnome2-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../www/seamonkey/gecko-depends.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
