# $NetBSD: Makefile,v 1.79 2025/09/28 18:52:16 tnn Exp $

DISTNAME=	xmlrpc-c-1.51.04
# the "super stable" branch
PKGNAME=	${DISTNAME:S/-c-/-c-ss-/}
PKGREVISION=	19
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlrpc-c/}
EXTRACT_SUFX=	.tgz
# It's actually not a compressed tar file
EXTRACT_OPTS+=	-c none

#/usr/bin/ld: ./libxmlrpc_server++.a(registry.o): relocation R_X86_64_32S against `_ZTVN8xmlrpc_c8callInfoE' can not be used when making a shared object; recompile with -fPIC
#./libxmlrpc_server++.a: could not read symbols: Bad value
MAKE_JOBS_SAFE=	no

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlrpc-c.sourceforge.net/
COMMENT=	Library for writing an XML-RPC server or client in C or C++
LICENSE=	modified-bsd

CONFLICTS+=	xmlrpc-c-[0-9]*
SUPERSEDES+=	xmlrpc-c-[0-9]*

# Sometimes can't open ../xmltok/libxmlrpc_xmltok.la
#MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c99 c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
MAKE_FILE=		GNUmakefile
MAKE_ENV=		CFLAGS_COMMON=${CFLAGS:M*:Q}
MAKE_ENV+=		CXXFLAGS_COMMON=${CXXFLAGS:M*:Q}
MAKE_ENV+=		LADD=${LDFLAGS:M*:Q}
TEST_TARGET=		check

PTHREAD_LINKFLAGS=	${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_MESSAGE.pthread=	Fixing config scripts.
SUBST_FILES.pthread=	xmlrpc-c-config.*
SUBST_SED.pthread=	-e 's/-lpthread/${PTHREAD_LINKFLAGS:Q}/'
SUBST_SED.pthread+=	-e 's/-L\(.\)libdir/-L\1libdir ${COMPILER_RPATH_FLAG}\1libdir/'

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE=1	# asprintf
LDFLAGS.OpenBSD+=	${PTHREAD_LINKFLAGS}

# TODO: really use pkgsrc expat
# this builds against the included libexpat, not the pkgsrc version
# see https://www.openwall.com/lists/oss-security/2025/04/09/4 for details
# and a possible patch
#post-extract:
#	${RM} -rf ${WRKSRC}/lib/expat

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
