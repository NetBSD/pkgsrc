# $NetBSD: Makefile,v 1.1.1.1 2008/12/20 00:13:07 jmcneill Exp $
#

DISTNAME=	qgtkstyle-r868
CATEGORIES=	x11
# no upstream releases; svn snapshot location
MASTER_SITES=	http://www.invisible.ca/~jmcneill/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labs.trolltech.com/page/Projects/Styles/GtkStyle
COMMENT=	Qt style rendered using GTK

PKG_DESTDIR_SUPPORT=    user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
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
