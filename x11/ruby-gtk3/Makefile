# $NetBSD: Makefile,v 1.15 2023/10/21 17:11:54 gdt Exp $
#

DISTNAME=		gtk3-${VERSION}
COMMENT=		Ruby binding of GTK+-3.x
PKGREVISION=		1
CATEGORIES=		x11

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gtk3-[0-9]*
SUPERSEDES+=		ruby-gnome2-gtk3-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-atk>=${VERSION}:../../devel/ruby-atk
DEPENDS+=		${RUBY_PKGPREFIX}-gdk3>=${VERSION}:../../graphics/ruby-gdk3

USE_TOOLS+=		pkg-config

.include "../../graphics/ruby-gdk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
