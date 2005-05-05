# $NetBSD: Makefile,v 1.2 2005/05/05 03:23:08 rh Exp $
#

DISTNAME=		sope-4.4beta.6-voyager-r758
PKGNAME=		sope-4.4rc6.758
CATEGORIES=		www gnustep
MASTER_SITES=		ftp://ftp.opengroupware.org/sources/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sope.opengroupware.org/
COMMENT=		Set of frameworks for a complete web application server environment

BUILD_DEPENDS+=		bash-[0-9]*:../../shells/bash

WRKSRC=			${WRKDIR}/sope
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gnustep
CONFIGURE_ARGS+=	--enable-strip
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

.include "../../devel/libFoundation/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
