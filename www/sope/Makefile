# $NetBSD: Makefile,v 1.4 2005/10/01 00:14:16 rh Exp $
#

DISTNAME=		sope-4.5.4-nevermind-r878
PKGNAME=		sope-4.5.4
PKGREVISION=		1
CATEGORIES=		www gnustep
MASTER_SITES=		ftp://ftp.opengroupware.org/nightly/sources/releases/ \
			http://download.opengroupware.org/nightly/sources/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sope.opengroupware.org/
COMMENT=		Set of frameworks for a complete web application server environment

BUILD_DEPENDS+=		bash-[0-9]*:../../shells/bash

WRKSRC=			${WRKDIR}/sope
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gnustep
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--disable-debug
CONFIG_SHELL=		${PREFIX}/bin/bash
MAKE_ENV+=		ADDITIONAL_OBJCFLAGS="-Wno-import"

pre-configure:
	cd ${WRKSRC}						&&	\
	${CP} ${CONFIGURE_SCRIPT} ${CONFIGURE_SCRIPT}.bak	&&	\
	${SED} < ${CONFIGURE_SCRIPT}.bak > ${CONFIGURE_SCRIPT}		\
		-e 's|/usr/local|${PREFIX}|g'

post-configure:
	cd ${WRKSRC}/sope-core/NGStreams			&&	\
	${LN} -s `${FIND} ${GNUSTEP_HOST_CPU} -name config.h` .

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libFoundation/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
