# $NetBSD: Makefile,v 1.9 2003/08/31 19:56:04 jdolecek Exp $

MODNAME=		xslt
PKGREVISION=		# empty
CATEGORIES+=		textproc
COMMENT=		PHP4 extension for XSLT functions (Sablotron backend)

USE_BUILDLINK2=		YES

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

.include "../../textproc/sablotron/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
