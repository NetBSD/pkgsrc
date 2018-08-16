# $NetBSD: Makefile,v 1.30 2018/08/16 18:55:13 adam Exp $

DISTNAME=	xmltooling-1.5.6
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://www.shibboleth.net/downloads/c++-opensaml/2.5.5/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://shibboleth.net/
COMMENT=	High level interface for XML processing library
LICENSE=	apache-2.0

BROKEN=		xerces-c needs C++11, but xmltooling does not support this yet

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/log4shib/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
