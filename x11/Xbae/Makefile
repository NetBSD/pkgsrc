# $NetBSD: Makefile,v 1.13 2002/04/17 03:03:07 jlam Exp $
#

DISTNAME=	Xbae-4.9.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.lesstif.org/Xbae.html
COMMENT=	Motif-compatible widgets: XbaeMatrix, XbaeCaption, XbaeInput

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-motif-includes=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-motif-libraries=${BUILDLINK_DIR}/lib
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC}/ac_find_xbae.m4 ${PREFIX}/share/aclocal
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/ac_find_xbae.m4 \
		${LOCALBASE}/share/aclocal/ac_find_xbae.m4

.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
