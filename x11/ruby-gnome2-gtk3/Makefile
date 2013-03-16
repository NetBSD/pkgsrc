# $NetBSD: Makefile,v 1.3 2013/03/16 12:25:49 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtk3-${VERSION}
COMMENT=		Ruby binding of GTK+-3.x
CATEGORIES=		x11

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtk3-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gtk3

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdk3>=${VERSION}:../../graphics/ruby-gnome2-gdk3
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf

do-test:
	${RUN} cd ${WRKSRC}/gtk2/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.ruby-gnome2-gio+=	${RUBY_PKGPREFIX}-gnome2-gio>=${VERSION}
.include "../../devel/ruby-gnome2-gio/buildlink3.mk"
BUILDLINK_API_DEPENDS.ruby-gnome2-pango+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}
.include "../../devel/ruby-gnome2-pango/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
