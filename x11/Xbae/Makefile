# $NetBSD: Makefile,v 1.28 2011/12/09 14:36:36 drochner Exp $
#

DISTNAME=	xbae-4.51.01
PKGNAME=	Xbae-4.51.01
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xbae/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://xbae.sourceforge.net/
COMMENT=	Motif-compatible widgets: XbaeMatrix, XbaeCaption, XbaeInput

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-motif-includes=${MOTIFBASE}/include
CONFIGURE_ARGS+=	--with-motif-libraries=${MOTIFBASE}/lib

INSTALLATION_DIRS=	share/aclocal

post-install:
	${INSTALL_DATA} ${WRKSRC}/ac_find_xbae.m4 ${DESTDIR}${PREFIX}/share/aclocal

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
