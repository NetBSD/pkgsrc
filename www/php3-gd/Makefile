# $NetBSD: Makefile,v 1.6 2001/02/17 17:22:28 wiz Exp $
#

PKGNAME=	php-gd-${PHP_VERSION}

COMMENT=	PHP3 extension for GD graphics library

DEPENDS+=	gd-*:../../graphics/gd

USE_PERL5=	yes

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include -fPIC -DPIC -DCOMPILE_DL gd.c && \
		${LD} -Bshareable -o gd.so gd.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lgd -lintl -ljpeg -lpng -lttf -lm -lz

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/gd.so ${PREFIX}/lib/php3/
	${INSTALL_SCRIPT} ${WRKSRC}/extra/gd/bdf2gdfont ${PREFIX}/bin/

.include "../php3/Makefile"

# this must be done last, as it is explicitly disabled in php3's CONFIGURE_ARGS
CONFIGURE_ARGS+=--with-gd
