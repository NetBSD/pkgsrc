# $NetBSD: Makefile,v 1.12 2011/11/01 06:03:03 sbd Exp $
#

DISTNAME=	matchbox-nest-0.3
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://matchbox-project.org/sources/matchbox-nest/0.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matchbox-project.org/
COMMENT=	Matchbox Xnest wrapper

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
