# $NetBSD: Makefile,v 1.7 2016/03/05 11:29:35 jperkin Exp $
#

DISTNAME=		mod_limitipconn-0.23
EXTRACT_SUFX=		.tar.bz2
PKGNAME=		${DISTNAME:S/mod_/ap22-/}
PKGREVISION=		6
CATEGORIES=		www
MASTER_SITES=		http://dominia.org/djao/limit/
LICENSE=		apache-2.0


PATCH_SITES=		http://dominia.org/djao/limit/contrib/dg/
PATCHFILES=		mod_limitipconn_local_IP_patch_2.diff

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://dominia.org/djao/limitipconn2.html
COMMENT=		Limits per-IP connections to an Apache 2 server

APACHE_MODULE=		yes
MAKE_FLAGS+=		APXS=${APXS:Q}
USE_LIBTOOL=		yes

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${BUILDLINK_PREFIX.apache}/share/httpd/build/instdso.sh \
		SH_LIBTOOL=${BUILDLINK_PREFIX.apache}/share/httpd/build/libtool \
		${WRKSRC}/mod_limitipconn.la \
		${DESTDIR}${PREFIX}/lib/httpd
post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mod_limitipconn
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mod_limitipconn/

.include "../../www/apache22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
