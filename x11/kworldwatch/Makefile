# $NetBSD: Makefile,v 1.7 2000/07/10 15:08:21 agc Exp $
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
CONFIGURE_ARGS+=--datadir=${X11BASE}/share/kde \
		--with-qt-dir=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1 \
		--with-qt-libraries='`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1/lib -L${LOCALBASE}/lib' \
		--enable-path-check
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		MOC=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1/bin/moc \
		QTDIR=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1 \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
