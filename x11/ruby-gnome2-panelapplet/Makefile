# $NetBSD: Makefile,v 1.18 2009/08/26 19:58:41 sno Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-panelapplet-${VERSION}
COMMENT=		Ruby binding of libpanel-applet-2.6.x
PKGREVISION=		1
CATEGORIES=		x11 gnome

CONFLICTS+=		ruby-gnome2-panelapplet-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	panel-applet

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gnome>=${VERSION}:../../x11/ruby-gnome2-gnome

USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
