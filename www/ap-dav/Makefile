# $NetBSD: Makefile,v 1.1.1.1 2001/05/16 02:11:54 jlam Exp $

DISTNAME=		mod_dav-1.0.2-1.3.6
PKGNAME=		ap-dav-1.0.2
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/mod_dav/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.webdav.org/mod_dav/
COMMENT=		Apache WebDAV module

DEPENDS+=		apache>=1.3.9:../../www/apache
# For "apxs":
BUILD_DEPENDS=		perl>=${PERL5_REQD}:../../lang/perl5

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-apxs="${LOCALBASE}/sbin/apxs"

AP_MODULE_DIR=		${PREFIX}/lib/httpd
DOCDIR=			${PREFIX}/share/doc/mod_dav
HTMLDIR=		${PREFIX}/share/doc/html/mod_dav

do-install:
	${INSTALL_DATA} ${WRKSRC}/libdav.so ${AP_MODULE_DIR}/mod_dav.so
	${INSTALL_DATA_DIR} ${DOCDIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.html ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
