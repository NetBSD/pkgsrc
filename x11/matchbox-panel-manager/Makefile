# $NetBSD: Makefile,v 1.4 2006/03/04 21:31:10 jlam Exp $
#

DISTNAME=	matchbox-panel-manager-0.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/matchbox-panel-manager/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Manager panel for the Matchbox desktop

USE_DIRS+=	gnome2-1.5
GNU_CONFIGURE=	yes

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
