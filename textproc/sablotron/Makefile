# $NetBSD: Makefile,v 1.5 2002/01/01 03:11:18 jlam Exp $

DISTNAME=		Sablot-0.71
PKGNAME=		sablotron-0.71
CATEGORIES=		textproc
MASTER_SITES=		http://download-2.gingerall.cz/download/sablot/

MAINTAINER=		uithuis@dds.nl
HOMEPAGE=		http://www.gingerall.com/charlie/ga/xml/p_sab.xml
COMMENT=		XML toolkit implementing XSLT, DOM, and XPath

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=  	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/tools/ltconfig

.include "../../converters/libiconv/buildlink.mk"
.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
