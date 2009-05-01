# $NetBSD: Makefile,v 1.17 2009/05/01 15:03:21 zafer Exp $
#

DISTNAME=	wmtime-1.0b2
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	http://web.cs.mun.ca/~gstarkes/wmaker/dockapps/files/ \
		http://www.NetBSD.org/~ad/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Time/Date applet for WindowMaker

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/wmtime.app
USE_IMAKE=	YES
CONFIGURE_DIRS=	wmtime
BUILD_DIRS=	${CONFIGURE_DIRS}

post-extract:
	${CP} ${WRKSRC}/Imakefile ${WRKSRC}/wmtime/Imakefile

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
