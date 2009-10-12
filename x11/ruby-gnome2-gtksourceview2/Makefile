# $NetBSD: Makefile,v 1.3 2009/10/12 03:09:33 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtksourceview2-${VERSION}
COMMENT=		Ruby binding of gtksourceview2
CATEGORIES=		x11

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtksourceview2

USE_TOOLS+=		pkg-config

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

do-test:
	${RUN} cd ${WRKSRC}/gtk/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
