# $NetBSD: Makefile,v 1.69 2026/01/07 08:49:10 wiz Exp $

DISTNAME=	xmltooling-3.3.0
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://shibboleth.net/
COMMENT=	High level interface for XML processing library
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
USE_TOOLS+=		pkg-config

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/log4shib/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../mk/tools/replace.mk"
