# $NetBSD: Makefile,v 1.22 2005/02/18 14:51:01 wiz Exp $
#

DISTNAME=	xbae-4.51.01
PKGNAME=	Xbae-4.51.01
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xbae/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://xbae.sourceforge.net/
COMMENT=	Motif-compatible widgets: XbaeMatrix, XbaeCaption, XbaeInput

USE_BUILDLINK3=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-motif-includes=${MOTIFBASE}/include
CONFIGURE_ARGS+=	--with-motif-libraries=${MOTIFBASE}/lib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC}/ac_find_xbae.m4 ${PREFIX}/share/aclocal

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
