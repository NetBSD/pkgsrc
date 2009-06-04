# $NetBSD: Makefile,v 1.3 2009/06/04 16:06:49 drochner Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-vte-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of vte
CATEGORIES=		x11

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	vte

DEPENDS+=               ${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
