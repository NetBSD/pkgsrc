# $NetBSD: Makefile,v 1.10 2000/07/14 16:04:28 agc Exp $
#

DISTNAME=	kworldwatch-0.6
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org

DEPENDS+=	gettext-0.10.*:../../devel/gettext
DEPENDS+=	kde-1.1.2:../../x11/kde

CONFLICTS+=	kdetoys-*

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--datadir=`${SHOW_PREFIX1} kdebase ${SHOW_PREFIX2}`/share/kde \
		--with-qt-dir=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1 \
		--with-qt-libraries='`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1/lib -L${LOCALBASE}/lib' \
		--enable-path-check
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=`${SHOW_PREFIX1} kdebase ${SHOW_PREFIX2}` \
		MOC=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1/bin/moc \
		QTDIR=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1 \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
