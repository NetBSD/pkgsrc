# $NetBSD: Makefile,v 1.40 2018/11/12 03:53:10 ryoon Exp $
#

DISTNAME=	matchbox-panel-manager-0.1
PKGREVISION=	31
CATEGORIES=	x11
MASTER_SITES=	http://matchbox-project.org/sources/matchbox-panel-manager/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matchbox-project.org/
COMMENT=	Manager panel for the Matchbox desktop

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
LDFLAGS+=	-lX11	# direct link required for ld v2.22

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
