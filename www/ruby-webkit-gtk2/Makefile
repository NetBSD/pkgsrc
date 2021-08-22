# $NetBSD: Makefile,v 1.2 2021/08/22 17:02:44 tsutsui Exp $
#

VERSION=		3.4.3
DISTNAME=		webkit-gtk2-${VERSION}
CATEGORIES=		www

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://ruby-gnome2.osdn.jp/
COMMENT=		Ruby binding of WebKitGTK+ for GTK2+
LICENSE=		gnu-lgpl-v2.1

CONFLICTS+=		ruby-gnome2-webkit-gtk2-[0-9]*
SUPERSEDES+=		ruby-gnome2-webkit-gtk2-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-gtk2>=${VERSION}:../../x11/ruby-gtk2
DEPENDS+=	${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection
DEPENDS+=	webkit24-gtk>=1.10.2nb8:../../www/webkit24-gtk

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
