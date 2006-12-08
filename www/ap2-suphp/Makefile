# $NetBSD: Makefile,v 1.7 2006/12/08 23:34:11 xtraeme Exp $
#

DISTNAME=		suphp-0.6.0
PKGNAME=		ap2-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		http://www.suphp.org/download/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.suphp.org/download/
COMMENT=		SuEXEC-like wrapper for PHP scripts

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
GCC_REQD+=		3.0	# the C++ code uses the .at() method
CONFIGURE_ARGS+=	APXS=${APXS}
CONFIGURE_ARGS+=	--with-apache-user=${APACHE_USER:Q}
CONFIGURE_ARGS+=	--with-logfile=${VARBASE}/httpd/suphp_log

# I don't know why this is necessary, but it is.
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/httpd
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/apr-0

EGDIR=			${PREFIX}/share/examples/suphp
CONF_FILES=		${EGDIR}/suphp.conf ${PKG_SYSCONFDIR}/suphp.conf

USE_APR=		yes
PKG_APACHE_ACCEPTED=	apache2 apache22

SUBST_CLASSES+=		suphp
SUBST_STAGE.suphp=	post-configure
SUBST_FILES.suphp=	doc/suphp.conf-example
SUBST_SED.suphp=	s,wwwrun,${APACHE_USER},g

post-install:
	${INSTALL_DATA_DIR} ${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/doc/suphp.conf-example ${EGDIR}/suphp.conf

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
