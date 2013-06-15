# $NetBSD: Makefile,v 1.34 2013/06/15 09:39:34 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtksourceview2-${VERSION}
COMMENT=		Ruby binding of gtksourceview2
CATEGORIES=		x11

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtksourceview2-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gtksourceview2

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

do-test:
	${RUN} cd ${WRKSRC}/gtksourceview2/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
