# $NetBSD: Makefile,v 1.13 2012/09/07 19:17:52 adam Exp $
#

DISTNAME=	qwtplot3d-0.2.7
PKGREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qwtplot3d/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qwtplot3d.sourceforge.net/
COMMENT=	3D-widgets for qt4
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/qwtplot3d
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include lib

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

do-install:
	for f in ${WRKSRC}/include/*.h; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/include; \
	done
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/lib/libqwtplot3d.la ${DESTDIR}${PREFIX}/lib

.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
