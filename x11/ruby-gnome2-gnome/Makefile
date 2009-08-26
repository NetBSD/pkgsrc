# $NetBSD: Makefile,v 1.17 2009/08/26 19:58:40 sno Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnome-${VERSION}
PKGREVISION=		1
CATEGORIES=		gnome x11
COMMENT=		Ruby binding of libgnome/libgnomeui-2.x

CONFLICTS+=		ruby-gnome2-gnome-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gnome

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gnomecanvas>=${VERSION}:../../graphics/ruby-gnome2-gnomecanvas

USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
