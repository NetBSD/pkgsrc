# $NetBSD: Makefile,v 1.3 2006/02/05 23:11:40 joerg Exp $
#

DISTNAME=	matchbox-panel-manager-0.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/matchbox-panel-manager/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Manager panel for the Matchbox desktop

USE_DIRS+=	gnome2-1.5
GNU_CONFIGURE=	yes

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
