# $NetBSD: Makefile,v 1.3 2009/02/16 19:45:13 joerg Exp $
#

DISTNAME=	qgtkstyle-r868
PKGNAME=	qgtkstyle-0.0beta868
CATEGORIES=	x11
# no upstream releases; svn snapshot location
MASTER_SITES=	http://www.invisible.ca/~jmcneill/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labs.trolltech.com/page/Projects/Styles/GtkStyle
COMMENT=	Qt style rendered using GTK

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${QTDIR}/plugins/styles
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
	    ${WRKSRC}/libgtkstyle.la \
	    ${DESTDIR}${QTDIR}/plugins/styles/libgtkstyle.la

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
