# $NetBSD: Makefile,v 1.45 2013/06/15 09:39:34 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtk-${VERSION}
COMMENT=		Ruby binding of GTK+-2.x
CATEGORIES=		x11

CONFLICTS+=		ruby-gnome2-gtk-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtk-[0-9]*

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
