# $NetBSD: Makefile,v 1.16 2001/09/27 23:19:01 jlam Exp $
#

DISTNAME=	khostchooser-0.3
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1.2/apps/network/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net
COMMENT=	KDE Chooser replacement for X

BUILD_USES_MSGFMT=	yes
DEPENDS+=	kdelibs-1.1.2:../../x11/kdelibs
DEPENDS+=	libungif-[0-9]*:../../graphics/libungif

WRKSRC=		${WRKDIR}/khostchooser

USE_X11BASE=	YES
USE_XPM=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/kde \
		--with-qt-dir=${QT1DIR}/qt1
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${QT1DIR}/qt1/lib
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		QTDIR=${QT1DIR}/qt1 \
		MOC=${QT1DIR}/qt1/bin/moc \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
