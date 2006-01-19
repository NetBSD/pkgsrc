# $NetBSD: Makefile,v 1.6 2006/01/19 22:15:58 joerg Exp $
#

DISTNAME=		sope-4.5.4-nevermind-r878
PKGNAME=		sope-4.5.4
PKGREVISION=		2
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

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${CONFIGURE_SCRIPT}
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_STAGE.paths=	pre-configure

pre-configure:
	for f in ${WRKSRC}/*/config.guess ${WRKSRC}/*/*/config.guess; do \
	    ${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess $$f; \
	done
	for f in ${WRKSRC}/*/config.sub ${WRKSRC}/*/*/config.sub; do \
	    ${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub $$f; \
	done

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
