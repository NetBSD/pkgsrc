# $NetBSD: Makefile,v 1.5 2001/04/02 20:06:15 wiz Exp $
#

DISTNAME=	kdelibdocs_kdoc2-1.1
PKGNAME=	kdelibdocs-1.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.kdevelop.org/pub/kdevelop/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	KDE library documentation

BUILD_USES_MSGFMT=	yes
DEPENDS+=       kdelibs-1.*:../../x11/kdelibs

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=    yes
LTCONFIG_OVERRIDE=      ${WRKSRC}/admin/ltconfig
GNU_CONFIGURE=  yes

EVAL_PREFIX+=   QT1DIR=qt1

CONFIGURE_ARGS=	--datadir=${PREFIX}/share/kde \
		--with-qt-dir=${QT1DIR}/qt1 \
		--with-qtdoc-dir=${QT1DIR}/qt1/share/doc

CFLAGS+=        -I${LOCALBASE}/include

CONFIGURE_ENV=  KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
