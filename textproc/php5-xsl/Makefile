# $NetBSD: Makefile,v 1.6 2006/06/04 16:26:55 joerg Exp $

MODNAME=		xsl
CATEGORIES+=		textproc
COMMENT=		PHP5 extension for XSLT functions

CONFLICTS=	php-xsl-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

# build uses includes of the DOM extension, so need to extract that too
EXTRACT_ELEMENTS=	${DISTNAME}/ext/${MODNAME} ${DISTNAME}/ext/dom
WRKSRC=			${WRKDIR}/${DISTNAME}/ext/${MODNAME}

PHP_VERSIONS_ACCEPTED=	5
.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
