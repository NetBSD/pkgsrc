# $NetBSD: Makefile,v 1.1.1.1 2002/01/01 03:48:14 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		xslt
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for XSLT functions (Sablotron backend)

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-${MODNAME}-sablot=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}

# libsablot.so depends on libiconv.so, so just force the configure script
# to find it.
#
CONFIGURE_ENV+=		ac_cv_lib_c_iconv_open=yes
CONFIGURE_ENV+=		XSLT_SHARED_LIBADD="-liconv"
LIBS+=			-liconv

.include "../../textproc/sablotron/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
