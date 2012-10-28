# $NetBSD: Makefile,v 1.17 2012/10/28 06:30:08 asau Exp $
#

DISTNAME=		suphp-0.7.1
PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		http://www.suphp.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.suphp.org/
COMMENT=		SuEXEC-like wrapper for PHP scripts
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		lex
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
GCC_REQD+=		3.0	# the C++ code uses the .at() method
CONFIGURE_ARGS+=	APXS=${APXS}
CONFIGURE_ARGS+=	--with-apache-user=${APACHE_USER}
CONFIGURE_ARGS+=	--with-logfile=${VARBASE}/httpd/suphp_log
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/suphp
CONF_FILES=		${EGDIR}/suphp.conf ${PKG_SYSCONFDIR}/suphp.conf

USE_APR=		yes
PKG_APACHE_ACCEPTED=	apache2 apache22

SUBST_CLASSES+=		suphp
SUBST_STAGE.suphp=	post-configure
SUBST_FILES.suphp=	doc/suphp.conf-example
SUBST_SED.suphp=	-e "s,wwwrun,${APACHE_USER},g"
SUBST_SED.suphp+=	-e "s,/var/log/suphp.log,${VARBASE}/httpd/suphp_log,g"
SUBST_SED.suphp+=	-e "s,/usr/bin/php,${PREFIX}/libexec/cgi-bin/php,g"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/suphp.conf-example ${DESTDIR}${EGDIR}/suphp.conf

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
