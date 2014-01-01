# $NetBSD: Makefile,v 1.25 2014/01/01 11:52:06 wiz Exp $

DISTNAME=	redland-1.0.16
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://librdf.org/
COMMENT=	Libraries supporting the Resource Description Framework (RDF)
LICENSE=	gnu-lgpl-v2.1 OR apache-2.0

USE_TOOLS+=	gmake perl pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bdb.buildlink3.mk"

.if empty(BDB_LIBS)
CONFIGURE_ARGS+=	--with-bdb-dbname=c
.else
CONFIGURE_ARGS+=	--with-bdb-dbname=${BDB_TYPE}
.endif
CONFIGURE_ARGS+=	--with-bdb-lib=${BDBBASE}/lib
CONFIGURE_ARGS+=	--with-bdb-include=${BDBBASE}/${BUILDLINK_INCDIRS.${BDB_TYPE}}
CONFIGURE_ARGS+=	--with-ltdl-include=${BUILDLINK_PREFIX.libltdl}/include
CONFIGURE_ARGS+=	--with-ltdl-lib=${BUILDLINK_PREFIX.libltdl}/lib
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-postgresql=no
CONFIGURE_ARGS+=	--with-sqlite=no
CONFIGURE_ARGS+=	--with-threestore=no
CONFIGURE_ARGS+=	--with-raptop=system
CONFIGURE_ARGS+=	--with-rasqal=system
CONFIGURE_ARGS+=	--with-virtuoso=no
CONFIGURE_ENV+=		ac_cv_path_IODBC_CONFIG=no

PKGCONFIG_OVERRIDE+=	redland.pc.in

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.raptor2+=	raptor2>=2.0.7
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../textproc/rasqal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
