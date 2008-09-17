# $NetBSD: Makefile,v 1.12 2008/09/17 00:21:50 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtk-${VERSION}
CATEGORIES=		x11
COMMENT=		Ruby binding of GTK+-2.x

CONFLICTS+=		ruby-gnome2-gtk-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtk

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf

USE_TOOLS+=		pkg-config

do-test:
	${RUN} cd ${WRKSRC}/gtk/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/ruby-gnome2-pango/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
