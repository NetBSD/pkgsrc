# $NetBSD: Makefile,v 1.6 2012/08/17 15:35:24 taca Exp $

MODNAME=		xsl
CATEGORIES+=		textproc
COMMENT=		PHP extension for XSLT functions

CONFLICTS=	php-xsl-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

# uses symbols from DOM extension, so add explicit depends
DEPENDS+=		${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom

# build uses includes of the DOM extension, so need to extract that too
EXTRACT_ELEMENTS=	${DISTNAME}/ext/${MODNAME} ${DISTNAME}/ext/dom
WRKSRC=			${WRKDIR}/${DISTNAME}/ext/${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
