# $NetBSD: Makefile,v 1.2 1998/12/19 23:06:59 christos Exp $
#

DISTNAME=	xpaint-2.5.6
CATEGORIES=	x11
MASTER_SITES=	http://www.danbbs.dk/~torsten/xpaint/

MAINTAINER=	christos@netbsd.org

DEPENDS+=	tiff-3.4:../../graphics/tiff png-1.0.2:../../graphics/png

USE_IMAKE=	yes

WRKSRC=		${WRKDIR}/xpaint

post-patch:
	@${MV} ${WRKSRC}/Local.config ${WRKSRC}/Local.config.dist
	@${SED} -e 's#@LOCALBASE@#${LOCALBASE}#' < ${WRKSRC}/Local.config.dist \
	> ${WRKSRC}/Local.config

.include "../../mk/bsd.pkg.mk"
