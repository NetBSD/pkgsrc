# $NetBSD: Makefile,v 1.2 2009/08/29 13:06:34 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/xcb/}
CATEGORIES=	multimedia
COMMENT=	The XCB video output plugins for xine-lib

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=	${WRKSRC}/src/video_out
CONFIGURE_ARGS+= --with-xcb
CONFIGURE_ARGS+= --without-x

INSTALLATION_DIRS=	lib/xine/plugins/${XINE_MOD_DIR_VER}

do-install:
	cd ${WRKSRC}/src/video_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_vo_out_xcbshm.la ${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}
	cd ${WRKSRC}/src/video_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_vo_out_xcbxv.la ${DESTDIR}${PREFIX}/lib/xine/plugins/${XINE_MOD_DIR_VER}

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
