# $NetBSD: Makefile,v 1.19 2009/05/30 00:20:42 zafer Exp $
#

DISTNAME=	catclock
PKGNAME=	catclock-0.0
PKGREVISION=	5
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Variant of the MIT xclock with a "cat" mode

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

post-patch:
	${RM} ${WRKSRC}/makefile ${WRKSRC}/pwd.h
	${MV} ${WRKSRC}/xclock.man ${WRKSRC}/catclock.man
	${SED} 's/^XClock/Catclock/g' <${WRKSRC}/xclock.ad >${WRKSRC}/Catclock.ad

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
