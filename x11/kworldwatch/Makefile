# $NetBSD: Makefile,v 1.9 2000/07/11 14:53:47 agc Exp $
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
CONFIGURE_ARGS+=--datadir=`${MAKE} show-kdebase-prefix`/share/kde \
		--with-qt-dir=`${MAKE} show-qt1-prefix`/qt1 \
		--with-qt-libraries='`${MAKE} show-qt1-prefix`/qt1/lib -L${LOCALBASE}/lib' \
		--enable-path-check
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=`${MAKE} show-kdebase-prefix` \
		MOC=`${MAKE} show-qt1-prefix`/qt1/bin/moc \
		QTDIR=`${MAKE} show-qt1-prefix`/qt1 \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
