# $NetBSD: Makefile,v 1.46 2024/05/29 16:34:47 adam Exp $

DISTNAME=	mod_authnz_crowd-2.2.2
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//:S/_/-/}
PKGREVISION=	43
CATEGORIES=	www
MASTER_SITES=	http://downloads.atlassian.com/software/crowd/downloads/cwdapache/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://confluence.atlassian.com/display/CROWD/Integrating+Crowd+with+Apache
COMMENT=	Apache module for Crowd authentication
LICENSE=	apache-2.0

APACHE_MODULE=		yes

DEPENDS+=	${APACHE_PKG_PREFIX}-subversion>0:../../www/ap2-subversion

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf

CONFIGURE_ENV+=	ac_cv_path_HTTPD=${BUILDLINK_PREFIX.apache}/sbin/httpd
CONFIGURE_ENV+=	APXS=${APXS:Q}
CONFIGURE_ENV+=	BUILDLINK_PREFIX_apache=${BUILDLINK_PREFIX.apache}
CONFIGURE_ENV+=	BUILDLINK_PREFIX_subversion=${BUILDLINK_PREFIX.subversion-base}

GNU_CONFIGURE_APXS2=	no

BUILDLINK_TRANSFORM+=	opt:-O2:-O1

INSTALLATION_DIRS+=	lib/httpd

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

do-install:
	for mod in mod_authnz_crowd.la svn/mod_authz_svn_crowd.la; do \
		${PREFIX}/share/httpd/build/instdso.sh \
		    SH_LIBTOOL=${PREFIX}/share/httpd/build/libtool \
		    ${WRKSRC}/src/$$mod ${DESTDIR}${PREFIX}/lib/httpd; \
	done

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
