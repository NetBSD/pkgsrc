# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:39 tsutsui Exp $
#

DISTNAME=		webkit-gtk2-${VERSION}
COMMENT=		Ruby binding of WebKitGTK+ for GTK2+
CATEGORIES=		www

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-webkit-gtk2-[0-9]*
SUPERSEDES+=		ruby-gnome2-webkit-gtk2-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-gtk2>=${VERSION}:../../x11/ruby-gtk2
DEPENDS+=	${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection
DEPENDS+=	webkit24-gtk>=1.10.2nb8:../../www/webkit24-gtk

.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
