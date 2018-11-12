# $NetBSD: Makefile,v 1.46 2018/11/12 03:53:08 ryoon Exp $
#

DISTNAME=		gtk-chtheme-0.3.1
PKGNAME=		gtk2-chtheme-0.3.1
PKGREVISION=		36
CATEGORIES=		x11
MASTER_SITES=		http://plasmasturm.org/code/gtk-chtheme/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kirtai@users.sourceforge.net
HOMEPAGE=		http://plasmasturm.org/code/gtk-chtheme/
COMMENT=		GTK+2 theme changer with preview

USE_TOOLS+=		gmake perl pkg-config
REPLACE_PERL=		replace

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
