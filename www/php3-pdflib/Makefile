# $NetBSD: Makefile,v 1.1.1.1 2001/05/03 17:00:22 wiz Exp $
#

PKGNAME=	php-pdflib-${PHP_VERSION}

COMMENT=	PHP3 extension for PDF library functions

DEPENDS+=	pdflib>=3.0:../../print/pdflib

CONFIGURE_ARGS+=--with-pdflib=${LOCALBASE} \
		--with-jpeg-dir=${LOCALBASE} \
		--with-tiff-dir==${LOCALBASE}
CONFIGURE_ENV+= LIBS=-lpng
BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include -fPIC -DPIC -DCOMPILE_DL pdf.c && \
		${LD} -Bshareable -o pdflib.so pdf.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lpdf \
			 -L/usr/lib -R/usr/lib -lz

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/pdflib.so ${PREFIX}/lib/php3/

.include "../../www/php3/Makefile"
