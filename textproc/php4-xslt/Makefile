# $NetBSD: Makefile,v 1.6 2002/10/30 15:28:12 wiz Exp $

MODNAME=		xslt
CATEGORIES+=		textproc
COMMENT=		PHP4 extension for XSLT functions (Sablotron backend)

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-${MODNAME}-sablot=shared,${BUILDLINK_PREFIX.sablotron}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_PREFIX.expat}
# to make configure find libiconv
CONFIGURE_ENV+=		PHP_ICONV=${BUILDLINK_PREFIX.iconv:Q}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README.XSLT-BACKENDS ${DOCDIR}

.include "../../textproc/sablotron/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
