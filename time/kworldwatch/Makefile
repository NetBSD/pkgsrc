# $NetBSD: Makefile,v 1.8 2002/10/21 15:27:16 wiz Exp $
#

DISTNAME=	kworldwatch-0.6
PKGREVISION=	1
CATEGORIES=	x11 kde time
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Revolving world map indicating the time in each part of the world

BUILD_USES_MSGFMT=	yes

CONFLICTS+=	kdetoys-[0-9]*

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--datadir=${BUILDLINK_PREFIX.kdebase}/share/kde \
		--with-qt-dir=${QTDIR} \
		--with-qt-libraries='${QTDIR}/lib -L${LOCALBASE}/lib' \
		--enable-path-check
#CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${BUILDLINK_PREFIX.kdebase} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib"

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/kdebase/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
