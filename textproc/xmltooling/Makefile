# $NetBSD: Makefile,v 1.1.1.1 2010/03/15 18:45:36 pettai Exp $
#

DISTNAME=	xmltooling-${PKGVERSION}
PKGVERSION=	1.3.3
CATEGORIES=	textproc
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/opensaml/cpp/2.3/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://shibboleth.internet2.edu/
COMMENT=	High level interface for XML processing library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/log4shib/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
