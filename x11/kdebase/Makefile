# New ports collection makefile for:   kdebase
# Version required:    Beta2
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $NetBSD: Makefile,v 1.5 1998/02/23 23:36:46 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1997/11/27 00:35:27 se Exp
#

DISTNAME=	kdebase-Beta2-1
PKGNAME=	kdebase-2.1b
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta2/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta2/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta2/distribution/tgz/source/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt.1.3[0-9]:${PORTSDIR}/x11/qt \
		gif.[23].:${PORTSDIR}/graphics/giflib \
		jpeg.[67].:${PORTSDIR}/graphics/jpeg \
		kdecore.0.1[1-9]:${PORTSDIR}/x11/kdelibs \
		kdeui.0.1[0-9]:${PORTSDIR}/x11/kdelibs \
		jscript.0.[1-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw.0.1[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm.0.[1-9]:${PORTSDIR}/x11/kdelibs \
		mediatool.0.[6-9]:${PORTSDIR}/x11/kdelibs

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}" \
		"--x-inc=${X11BASE}/include -I${PREFIX}/include -I${PREFIX}/include/giflib" \
		"--x-lib=${X11BASE}/lib -L${PREFIX}/lib" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${X11BASE}/include/qt"
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

WRKSRC=		${WRKDIR}/kdebase

.include <bsd.port.mk>
