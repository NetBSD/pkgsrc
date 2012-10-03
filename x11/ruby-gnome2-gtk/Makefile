# $NetBSD: Makefile,v 1.35.2.1 2012/10/03 12:10:04 spz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtk-${VERSION}
COMMENT=		Ruby binding of GTK+-2.x
PKGREVISION=		3
CATEGORIES=		x11

CONFLICTS+=		ruby-gnome2-gtk-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtk-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtk2

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf

do-test:
	${RUN} cd ${WRKSRC}/gtk2/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.ruby-gnome2-pango+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}
.include "../../devel/ruby-gnome2-pango/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
