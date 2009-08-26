# $NetBSD: Makefile,v 1.3 2009/08/26 19:58:27 sno Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtkhtml2-${VERSION}
COMMENT=		Ruby binding of gtkhtml2
PKGREVISION=		1
CATEGORIES=		www

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtkhtml2

DEPENDS+=               ${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
