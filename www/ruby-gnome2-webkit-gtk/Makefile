# $NetBSD: Makefile,v 1.9 2017/06/11 05:51:41 tsutsui Exp $
#

DISTNAME=		webkit-gtk-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
COMMENT=		Ruby binding of WebKitGTK+
CATEGORIES=		www

MAINTAINER=		tsutsui@NetBSD.org

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}:../../x11/ruby-gnome2-gtk3
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	webkit24-gtk3>=1.10.2nb6:../../www/webkit24-gtk3

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
