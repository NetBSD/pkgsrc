# $NetBSD: Makefile,v 1.20 2004/11/23 16:35:55 wiz Exp $
#

DISTNAME=	Xbae-4.9.1
PKGREVISION=	1
CATEGORIES=	x11
#MASTER_SITES=	ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/ \
#		${MASTER_SITE_SOURCEFORGE:=xbae/}
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
