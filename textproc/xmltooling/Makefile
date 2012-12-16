# $NetBSD: Makefile,v 1.9 2012/12/16 01:52:36 obache Exp $

DISTNAME=	xmltooling-1.4.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.shibboleth.net/downloads/c++-opensaml/2.4.3/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://shibboleth.internet2.edu/
COMMENT=	High level interface for XML processing library
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

.include "../../devel/log4shib/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
