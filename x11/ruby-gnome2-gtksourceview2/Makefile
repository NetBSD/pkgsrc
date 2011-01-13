# $NetBSD: Makefile,v 1.10 2011/01/13 13:40:05 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtksourceview2-${VERSION}
COMMENT=		Ruby binding of gtksourceview2
PKGREVISION=		1
CATEGORIES=		x11

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtksourceview2-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtksourceview2

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

do-test:
	${RUN} cd ${WRKSRC}/gtk/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
