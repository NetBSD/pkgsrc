# $NetBSD: Makefile,v 1.21 2004/11/23 17:04:15 wiz Exp $
#

DISTNAME=	xbae-4.50.99
PKGNAME=	Xbae-4.50.99
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xbae/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://xbae.sourceforge.net/
COMMENT=	Motif-compatible widgets: XbaeMatrix, XbaeCaption, XbaeInput

USE_BUILDLINK3=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-motif-includes=${MOTIFBASE}/include
CONFIGURE_ARGS+=	--with-motif-libraries=${MOTIFBASE}/lib
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC}/ac_find_xbae.m4 ${PREFIX}/share/aclocal
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/ac_find_xbae.m4 \
		${LOCALBASE}/share/aclocal/ac_find_xbae.m4

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
