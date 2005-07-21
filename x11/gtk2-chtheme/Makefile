# $NetBSD: Makefile,v 1.5 2005/07/21 16:30:00 wiz Exp $
#

DISTNAME=		gtk-chtheme-0.3.1
PKGNAME=		gtk2-chtheme-0.3.1
CATEGORIES=		x11
MASTER_SITES=		http://plasmasturm.org/programs/gtk-chtheme/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kirtai@users.sourceforge.net
HOMEPAGE=		http://plasmasturm.org/programs/gtk-chtheme/
COMMENT=		GTK+2 theme changer with preview

USE_TOOLS+=		gmake perl
REPLACE_PERL=		replace

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
