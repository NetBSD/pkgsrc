# $NetBSD: Makefile,v 1.17 2004/02/14 17:21:55 jlam Exp $
#

DISTNAME=	Xbae-4.9.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.lesstif.org/Xbae.html
COMMENT=	Motif-compatible widgets: XbaeMatrix, XbaeCaption, XbaeInput

USE_BUILDLINK2=		YES
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

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
