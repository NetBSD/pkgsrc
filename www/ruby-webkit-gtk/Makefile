# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:39 tsutsui Exp $
#

DISTNAME=		webkit-gtk-${VERSION}
COMMENT=		Ruby binding of WebKitGTK+
CATEGORIES=		www

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-webkit-gtk-[0-9]*
SUPERSEDES+=		ruby-gnome2-webkit-gtk-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-gtk3>=${VERSION}:../../x11/ruby-gtk3
DEPENDS+=	webkit24-gtk3>=1.10.2nb6:../../www/webkit24-gtk3

.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
