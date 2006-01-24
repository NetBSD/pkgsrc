# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:43 wiz Exp $
#

DISTNAME=		suphp-0.6.0
PKGNAME=		ap2-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.suphp.org/download/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.suphp.org/download/
COMMENT=		SuEXEC-like wrapper for PHP scripts

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
GCC_REQD+=		3.0	# the C++ code uses the .at() method
CONFIGURE_ARGS+=	APXS=apxs
CONFIGURE_ARGS+=	--with-apache-user=${APACHE_USER:Q}
CONFIGURE_ARGS+=	--with-logfile=${VARBASE}/httpd/suphp_log

# I don't know why this is necessary, but it is.
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/httpd
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/apr-0

EGDIR=			${PREFIX}/share/examples/suphp
CONF_FILES=		${EGDIR}/suphp.conf ${PKG_SYSCONFDIR}/suphp.conf

SUBST_CLASSES+=		suphp
SUBST_STAGE.suphp=	post-configure
SUBST_FILES.suphp=	doc/suphp.conf-example
SUBST_SED.suphp=	s,wwwrun,${APACHE_USER},g

post-install:
	${INSTALL_DATA_DIR} ${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/doc/suphp.conf-example ${EGDIR}/suphp.conf

.include "../../www/apache2/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
