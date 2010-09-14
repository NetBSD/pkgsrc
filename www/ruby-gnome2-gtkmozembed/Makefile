# $NetBSD: Makefile,v 1.10 2010/09/14 11:02:57 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtkmozembed-${VERSION}
COMMENT=		Ruby binding of gtkmozembed
PKGREVISION=		3
CATEGORIES=		www

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtkmozembed

DEPENDS+=               ${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.ruby-gnome2-pango+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}
.include "../../devel/ruby-gnome2-pango/buildlink3.mk"
.include "../../devel/xulrunner/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
