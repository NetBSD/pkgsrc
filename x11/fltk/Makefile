# $NetBSD: Makefile,v 1.26 2003/02/17 15:28:03 dillo Exp $
#

DISTNAME=	fltk-1.0.11-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	1
VERS=		${DISTNAME:S/fltk-//:S/-source//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=FLTK/} \
		ftp://ftp.fltk.org/pub/fltk/${VERS}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERS}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces

USE_X11BASE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
USE_BUILDLINK2=		# defined
TEST_TARGET=		test

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-libtool=${PKGLIBTOOL}

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
