# $NetBSD: Makefile,v 1.10 2004/04/25 00:52:39 xtraeme Exp $

MODNAME=		xslt
PKGREVISION=		# empty
CATEGORIES+=		textproc
COMMENT=		PHP4 extension for XSLT functions (Sablotron backend)

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-${MODNAME}-sablot=${BUILDLINK_PREFIX.sablotron}
CONFIGURE_ARGS+=	--with-expat-dir=${BUILDLINK_PREFIX.expat}

# this is necessary so that PHP would find either the libc iconv
# or use the packaged iconv, as appropriate; see also converters/php4-iconv
CONFIGURE_ARGS+=	--with-iconv-dir
CONFIGURE_ENV+=		PHP_ICONV=${BUILDLINK_PREFIX.iconv:Q}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README.XSLT-BACKENDS ${DOCDIR}

.include "../../textproc/sablotron/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
