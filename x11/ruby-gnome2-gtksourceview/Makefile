# $NetBSD: Makefile,v 1.7 2010/06/13 22:45:52 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtksourceview-${VERSION}
COMMENT=		Ruby binding of gtksourceview
PKGREVISION=		3
CATEGORIES=		x11

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtksourceview

DEPENDS+=               ${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
