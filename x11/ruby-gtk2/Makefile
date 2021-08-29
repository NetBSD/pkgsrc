# $NetBSD: Makefile,v 1.7 2021/08/29 16:57:18 tsutsui Exp $
#

DISTNAME=		gtk2-3.4.3
PKGREVISION=		1
CATEGORIES=		x11

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://ruby-gnome2.osdn.jp/
COMMENT=		Ruby binding of GTK+-2.x
LICENSE=		gnu-lgpl-v2.1

CONFLICTS+=		ruby-gnome2-gtk-[0-9]*
SUPERSEDES+=		ruby-gnome2-gtk-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-atk>=3.4.3:../../devel/ruby-atk
DEPENDS+=		${RUBY_PKGPREFIX}-pango>=3.4.3:../../devel/ruby-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gdk_pixbuf2>=3.4.3:../../graphics/ruby-gdk_pixbuf2

OVERRIDE_GEMSPEC+=	atk>=3.4.3 pango>=3.4.3 gdk_pixbuf2>=3.4.3

.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
