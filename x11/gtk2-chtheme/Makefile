# $NetBSD: Makefile,v 1.8 2006/02/05 23:11:34 joerg Exp $
#

DISTNAME=		gtk-chtheme-0.3.1
PKGNAME=		gtk2-chtheme-0.3.1
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		http://plasmasturm.org/programs/gtk-chtheme/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kirtai@users.sourceforge.net
HOMEPAGE=		http://plasmasturm.org/programs/gtk-chtheme/
COMMENT=		GTK+2 theme changer with preview

USE_TOOLS+=		gmake perl pkg-config
REPLACE_PERL=		replace

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
