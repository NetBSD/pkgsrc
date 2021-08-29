# $NetBSD: Makefile,v 1.3 2021/08/29 17:00:25 tsutsui Exp $
#

DISTNAME=		webkit-gtk2-3.4.3
PKGREVISION=		1
CATEGORIES=		www

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://ruby-gnome2.osdn.jp/
COMMENT=		Ruby binding of WebKitGTK+ for GTK2+
LICENSE=		gnu-lgpl-v2.1

CONFLICTS+=		ruby-gnome2-webkit-gtk2-[0-9]*
SUPERSEDES+=		ruby-gnome2-webkit-gtk2-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-gtk2>=3.4.3nb1:../../x11/ruby-gtk2
DEPENDS+=	${RUBY_PKGPREFIX}-gobject-introspection>=3.4.3:../../devel/ruby-gobject-introspection
DEPENDS+=	webkit24-gtk>=1.10.2nb8:../../www/webkit24-gtk

OVERRIDE_GEMSPEC+=	gobject-introspection>=3.4.3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
