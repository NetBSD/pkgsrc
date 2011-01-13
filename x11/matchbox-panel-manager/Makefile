# $NetBSD: Makefile,v 1.15 2011/01/13 13:40:01 wiz Exp $
#

DISTNAME=	matchbox-panel-manager-0.1
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://matchbox-project.org/sources/matchbox-panel-manager/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matchbox-project.org/
COMMENT=	Manager panel for the Matchbox desktop

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
