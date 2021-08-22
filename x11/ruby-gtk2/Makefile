# $NetBSD: Makefile,v 1.6 2021/08/22 17:02:44 tsutsui Exp $
#

VERSION=		3.4.3
DISTNAME=		gtk2-${VERSION}
CATEGORIES=		x11

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://ruby-gnome2.osdn.jp/
COMMENT=		Ruby binding of GTK+-2.x
LICENSE=		gnu-lgpl-v2.1

CONFLICTS+=		ruby-gnome2-gtk-[0-9]*
SUPERSEDES+=		ruby-gnome2-gtk-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-atk>=${VERSION}:../../devel/ruby-atk
DEPENDS+=		${RUBY_PKGPREFIX}-pango>=${VERSION}:../../devel/ruby-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gdk_pixbuf2>=${VERSION}:../../graphics/ruby-gdk_pixbuf2

.include "../../devel/ruby-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
