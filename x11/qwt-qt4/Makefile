# $NetBSD: Makefile,v 1.24 2013/02/06 23:21:15 jperkin Exp $

DISTNAME=	qwt-5.2.2
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qwt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/qwt/
COMMENT=	Qt widget library for technical purposes
LICENSE=	gnu-lgpl-v2
MAKE_JOBS_SAFE=		no

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

CONFLICTS=	qwtlib-[0-9]*

AUTO_MKDIRS=			yes
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

.include "../../x11/qt4-libs/buildlink3.mk"
# needs fix for "silent" qmake feature flag
BUILDLINK_API_DEPENDS.qt4-tools+= qt4-tools>=4.6.3nb1
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
