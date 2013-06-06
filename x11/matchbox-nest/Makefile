# $NetBSD: Makefile,v 1.17 2013/06/06 12:55:20 wiz Exp $
#

DISTNAME=	matchbox-nest-0.3
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	http://matchbox-project.org/sources/matchbox-nest/0.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matchbox-project.org/
COMMENT=	Matchbox Xnest wrapper

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
