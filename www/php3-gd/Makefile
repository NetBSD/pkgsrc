# $NetBSD: Makefile,v 1.3 1999/08/29 21:12:39 tron Exp $
#

PKGNAME=	php-gd-${PHP_VERSION}

DEPENDS+=	gd-*:../../graphics/gd

USE_PERL5=	yes

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include/gd -fPIC -DPIC -DCOMPILE_DL gd.c && \
		ld -Bshareable -o gd.so gd.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lgd

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/gd.so ${PREFIX}/lib/php3/
	${INSTALL_SCRIPT} ${WRKSRC}/extra/gd/bdf2gdfont ${PREFIX}/bin/

.include "../php3/Makefile"

# this must be done last, as it is explicitly disabled in php3's CONFIGURE_ARGS
CONFIGURE_ARGS+=--with-gd
