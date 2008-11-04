# $NetBSD: Makefile,v 1.1.1.1 2008/11/04 10:39:40 markd Exp $

DISTNAME=	redland-1.0.7
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://librdf.org
COMMENT=	libraries that support the Resource Description Framework (RDF)

USE_TOOLS+=	gmake perl pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.if empty(BDB_LIBS)
CONFIGURE_ARGS+=	--with-bdb-dbname=c
.else
CONFIGURE_ARGS+=	--with-bdb-dbname=${BDB_LIBS:Q}
.endif
CONFIGURE_ARGS+=	--with-bdb-lib=${BDBBASE}/lib
CONFIGURE_ARGS+=	--with-bdb-include=${BDBBASE}/${BUILDLINK_INCDIRS.${BDB_TYPE}}
CONFIGURE_ARGS+=	--with-postgresql=no
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-sqlite=no
CONFIGURE_ARGS+=	--with-threestore=no
CONFIGURE_ARGS+=	--with-raptop=system
CONFIGURE_ARGS+=	--with-rasqal=system

PKGCONFIG_OVERRIDE+=	librdf/redland.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/raptor/buildlink3.mk"
.include "../../textproc/rasqal/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
