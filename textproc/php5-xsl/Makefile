# $NetBSD: Makefile,v 1.3 2005/12/05 20:51:07 rillig Exp $

MODNAME=		xsl
CATEGORIES+=		textproc
COMMENT=		PHP5 extension for XSLT functions


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

# build uses includes of the DOM extension, so need to extract that too
EXTRACT_ELEMENTS=	${DISTNAME}/ext/${MODNAME} ${DISTNAME}/ext/dom
WRKSRC=			${WRKDIR}/${DISTNAME}/ext/${MODNAME}

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
