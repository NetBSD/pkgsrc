# $NetBSD: Makefile,v 1.5 2002/09/10 16:06:50 wiz Exp $

MODNAME=		xslt
CATEGORIES+=		textproc
PKGREVISION=		1
COMMENT=		PHP4 extension for XSLT functions (Sablotron backend)

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-${MODNAME}-sablot=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}

# libsablot.so depends on libiconv.so, so just force the configure script
# to find it.
#
CONFIGURE_ENV+=		ac_cv_lib_c_iconv_open=yes
CONFIGURE_ENV+=		XSLT_SHARED_LIBADD="-liconv"
LIBS+=			-liconv

PLIST_SRC+=		${.CURDIR}/PLIST.extras
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README.XSLT-BACKENDS ${DOCDIR}

.include "../../textproc/sablotron/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
