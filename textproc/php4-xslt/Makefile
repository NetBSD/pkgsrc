# $NetBSD: Makefile,v 1.14 2004/11/05 21:44:44 jdolecek Exp $

MODNAME=		xslt
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for XSLT functions (Sablotron backend)

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-${MODNAME}-sablot=${BUILDLINK_PREFIX.sablotron}
CONFIGURE_ARGS+=	--with-expat-dir=${BUILDLINK_PREFIX.expat}

# this is necessary so that PHP would find either the libc iconv
# or use the packaged iconv, as appropriate; using
# --with-iconv=shared,${BUILDLINK_PREFIX.iconv} assumes libiconv exists

.include "../../mk/bsd.prefs.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/buildlink3/bsd.builtin.mk"

.if !empty(USE_BUILTIN.iconv:M[nN][oO])
# use libiconv
CONFIGURE_ARGS+=	--with-iconv-dir=${BUILDLINK_PREFIX.iconv:Q}
.else
CONFIGURE_ARGS+=	--with-iconv-dir
.endif

PLIST_SRC+=		${.CURDIR}/PLIST.extras
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README.XSLT-BACKENDS ${DOCDIR}

PHP_VERSION_REQD=	4
.include "../../lang/php/ext.mk"
.include "../../textproc/sablotron/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
