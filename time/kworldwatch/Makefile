# $NetBSD: Makefile,v 1.2 2001/01/05 01:40:38 wiz Exp $
#

DISTNAME=	kworldwatch-0.6
CATEGORIES=	x11 kde time
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	kdebase-1.1.2:../../x11/kdebase

CONFLICTS+=	kdetoys-*

USE_LIBINTL=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

EVAL_PREFIX+=	QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS+=--datadir=${KDEBASEDIR}/share/kde \
		--with-qt-dir=${QT1DIR}/qt1 \
		--with-qt-libraries='${QT1DIR}/qt1/lib -L${LOCALBASE}/lib' \
		--enable-path-check
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${KDEBASEDIR} \
		MOC=${QT1DIR}/qt1/bin/moc \
		QTDIR=${QT1DIR}/qt1 \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
