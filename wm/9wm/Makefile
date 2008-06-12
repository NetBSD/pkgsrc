# $NetBSD: Makefile,v 1.15 2008/06/12 02:14:53 joerg Exp $

DISTNAME=		9wm-1.1
PKGREVISION=		2
CATEGORIES=		plan9 wm
MASTER_SITES=		ftp://ftp.freefriends.org/arnold/Source/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dhog.g7.org/dhog/9wm.html
COMMENT=		8 1/2-like Window Manager for X

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
USE_IMAKE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
