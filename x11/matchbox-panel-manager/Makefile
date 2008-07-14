# $NetBSD: Makefile,v 1.8 2008/07/14 12:56:19 joerg Exp $
#

DISTNAME=	matchbox-panel-manager-0.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/matchbox-panel-manager/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Manager panel for the Matchbox desktop

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=	gnome2-1.5
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
