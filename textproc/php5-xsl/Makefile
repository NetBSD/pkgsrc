# $NetBSD: Makefile,v 1.7 2007/09/04 21:40:09 jdolecek Exp $

MODNAME=		xsl
CATEGORIES+=		textproc
COMMENT=		PHP5 extension for XSLT functions

CONFLICTS=	php-xsl-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

# uses symbols from DOM extension, so add explicit depends
DEPENDS+=		php5-dom-*:../../textproc/php5-dom

# build uses includes of the DOM extension, so need to extract that too
EXTRACT_ELEMENTS=	${DISTNAME}/ext/${MODNAME} ${DISTNAME}/ext/dom
WRKSRC=			${WRKDIR}/${DISTNAME}/ext/${MODNAME}

PHP_VERSIONS_ACCEPTED=	5
.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
