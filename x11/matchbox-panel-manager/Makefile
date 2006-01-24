# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:58 wiz Exp $
#

DISTNAME=	matchbox-panel-manager-0.1
PKGREVISION=	1
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
