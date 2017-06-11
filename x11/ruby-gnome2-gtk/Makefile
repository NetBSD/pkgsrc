# $NetBSD: Makefile,v 1.63 2017/06/11 05:51:41 tsutsui Exp $
#

DISTNAME=		gtk2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtk-${VERSION}
COMMENT=		Ruby binding of GTK+-2.x
CATEGORIES=		x11

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gtk-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtk-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf

.include "../../devel/ruby-gnome2-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
