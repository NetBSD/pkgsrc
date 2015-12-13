# $NetBSD: Makefile,v 1.19 2015/12/13 10:52:16 tsutsui Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtksourceview3-${VERSION}
COMMENT=		Ruby binding of gtksourceview3
CATEGORIES=		x11

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtksourceview3-[0-9]*

RUBY_SETUP_SUBDIRS=	gtksourceview3
USE_RUBY_EXTCONF=	no
USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}:../../x11/ruby-gnome2-gtk3

do-test:
	${RUN} cd ${WRKSRC}/gtksourceview3/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
