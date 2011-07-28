# $NetBSD: Makefile,v 1.7 2011/07/28 22:24:16 pettai Exp $

DISTNAME=	xmltooling-1.4.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.shibboleth.net/downloads/c++-opensaml/2.4.3/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://shibboleth.internet2.edu/
COMMENT=	High level interface for XML processing library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

.include "../../devel/log4shib/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
