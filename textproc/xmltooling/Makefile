# $NetBSD: Makefile,v 1.55 2024/05/29 16:34:42 adam Exp $

DISTNAME=	xmltooling-3.1.0
PKGREVISION=	
PKGREVISION=	14
CATEGORIES=	textproc
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/3.1.0/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://shibboleth.net/
COMMENT=	High level interface for XML processing library
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc
USE_TOOLS+=		pkg-config

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/log4shib/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../mk/tools/replace.mk"
