# $NetBSD: Makefile,v 1.6 2006/06/11 14:43:13 joerg Exp $
#

DISTNAME=	matchbox-nest-0.3
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/matchbox-nest/0.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Matchbox Xnest wrapper

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
