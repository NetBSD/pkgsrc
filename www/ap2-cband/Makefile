# $NetBSD: Makefile,v 1.6 2014/06/10 15:22:17 joerg Exp $
#

DISTNAME=		mod-cband-0.9.7.5
PKGNAME=		${APACHE_PKG_PREFIX}-cband-${DISTNAME:S/mod-cband-//}
CATEGORIES=		www
MASTER_SITES=		http://cband.linux.pl/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://codee.pl/cband.html
COMMENT=		Bandwidth and connection limiting module for Apache 2
LICENSE=		gnu-gpl-v2

APACHE_MODULE_NAME=	mod_cband
DOC_DIR=		${PREFIX}/share/doc/${APACHE_MODULE_NAME}

APACHE_MODULE=		yes
PKG_APACHE_ACCEPTED=	apache22

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
BUILD_TARGET=

INSTALLATION_DIRS+=	lib/httpd share/doc/${APACHE_MODULE_NAME}

CONFIGURE_ENV+=		APXS=${APXS}

do-install:
	cd ${WRKSRC}/src && 							\
	    libexecdir=`${APXS} -q LIBEXECDIR` &&				\
	    ${APXS} -i -S LIBEXECDIR=${DESTDIR}"$${libexecdir}" 		\
		-n ${APACHE_MODULE_NAME} -i ${APACHE_MODULE_NAME}.la
	${INSTALL_DATA} ${WRKSRC}/doc/documentation.txt				\
		${DESTDIR}${DOC_DIR}/documentation.txt
	${INSTALL_DATA} ${WRKSRC}/doc/faq.txt ${DESTDIR}${DOC_DIR}/faq.txt

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
