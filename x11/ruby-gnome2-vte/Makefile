# $NetBSD: Makefile,v 1.27.2.1 2012/10/03 12:10:04 spz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-vte-${VERSION}
COMMENT=		Ruby binding of vte
PKGREVISION=		3
CATEGORIES=		x11

CONFLICTS+=		ruby[0-9][0-9]-gnome2-vte-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	vte

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
