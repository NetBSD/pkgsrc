# $NetBSD: Makefile,v 1.1.1.1 1999/07/04 00:50:35 hubertf Exp $
#

DISTNAME=	kworldwatch-0.6
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1.1/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org

#DEPENDS+=	gettext-0.10.35:../../devel/gettext
#DEPENDS+=	kde-1.1.1:../../x11/kde

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--datadir=${X11BASE}/share/kde \
		--with-qt-dir=${X11BASE} \
		--with-qt-includes='${X11BASE}/include/qt -I${LOCALBASE}/include' \
		--with-qt-libraries='${X11BASE}/lib -L${LOCALBASE}/lib' \
		--enable-path-check
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
