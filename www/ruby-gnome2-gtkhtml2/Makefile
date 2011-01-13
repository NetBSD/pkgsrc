# $NetBSD: Makefile,v 1.11 2011/01/13 13:39:40 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtkhtml2-${VERSION}
COMMENT=		Ruby binding of gtkhtml2
PKGREVISION=		1
CATEGORIES=		www

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtkhtml2-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtkhtml2

DEPENDS+=               ${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
