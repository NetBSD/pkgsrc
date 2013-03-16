# $NetBSD: Makefile,v 1.33 2013/03/16 12:25:49 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-vte-${VERSION}
COMMENT=		Ruby binding of vte
CATEGORIES=		x11

CONFLICTS+=		ruby[0-9][0-9]-gnome2-vte-[0-9]*

RUBY_EXTCONF_SUBDIRS=	vte

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
