# $NetBSD: Makefile,v 1.13 2004/01/03 18:49:54 reed Exp $
#

DISTNAME=	kworldwatch-0.6
PKGREVISION=	3
CATEGORIES=	x11 kde time
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@NetBSD.org
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
CONFIGURE_ENV=	KDEDIR=${BUILDLINK_PREFIX.kdebase} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="${KDE_LDFLAGS}"

FIX_RPATH+=	KDE_LDFLAGS
KDE_LDFLAGS=	-L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -L${X11BASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/kdebase/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
