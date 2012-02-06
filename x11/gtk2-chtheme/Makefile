# $NetBSD: Makefile,v 1.20 2012/02/06 12:41:59 wiz Exp $
#

DISTNAME=		gtk-chtheme-0.3.1
PKGNAME=		gtk2-chtheme-0.3.1
PKGREVISION=		11
CATEGORIES=		x11
MASTER_SITES=		http://plasmasturm.org/code/gtk-chtheme/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kirtai@users.sourceforge.net
HOMEPAGE=		http://plasmasturm.org/code/gtk-chtheme/
COMMENT=		GTK+2 theme changer with preview

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl pkg-config
REPLACE_PERL=		replace

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
