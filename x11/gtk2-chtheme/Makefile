# $NetBSD: Makefile,v 1.16 2011/01/13 13:39:46 wiz Exp $
#

DISTNAME=		gtk-chtheme-0.3.1
PKGNAME=		gtk2-chtheme-0.3.1
PKGREVISION=		8
CATEGORIES=		x11
MASTER_SITES=		http://plasmasturm.org/code/gtk-chtheme/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kirtai@users.sourceforge.net
HOMEPAGE=		http://plasmasturm.org/code/gtk-chtheme/
COMMENT=		GTK+2 theme changer with preview

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl pkg-config
REPLACE_PERL=		replace

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
