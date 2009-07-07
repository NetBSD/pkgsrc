# $NetBSD: Makefile,v 1.8 2009/07/07 18:25:13 tron Exp $

DISTNAME=	squid-3.1.0.9
PKGNAME=	${DISTNAME}	# Necessary for "pkgsrc/www/squid/options.mk"
CATEGORIES=	www
MASTER_SITES=	${SQUID_MASTER_SITES} \
		http://www.squid-cache.org/Versions/v3/3.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake
GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	destdir

POST_INSTALL_EXTRA=	install-error-pages

.include "../../www/squid/Makefile.squid"

CONFIGURE_ARGS+=	--with-default-user=${SQUID_USER}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/squid.pid

EGFILES+=     errors/errorpage.css
CONF_FILES+=  ${PREFIX}/${EGDIR}/errorpage.css ${PKG_SYSCONFDIR}/errorpage.css

SQUID_BACKENDS?=           ufs
SQUID_NTLM_AUTH_HELPERS?=  fakeauth
.include "../../www/squid/options.mk"

post-build:
	${CP} -pf ${WRKSRC}/src/squid.conf.documented \
	  ${WRKSRC}/src/squid.conf.default

install-error-pages:
	cd ${WRKSRC}/errors &&					\
	for DIR in *; do					\
	  if [ -d $$DIR ]; then				\
	    ERROR_DIR=${PREFIX}/share/squid/errors/$$DIR;	\
	    ${INSTALL_DATA_DIR} $$ERROR_DIR;			\
	    for FILE in $$DIR/ERR_*; do			\
	      ${INSTALL_DATA} $$FILE $$ERROR_DIR; 		\
	    done;						\
	  fi;							\
	done
	${LN} -s en ${PREFIX}/share/squid/errors/templates

.include "../../mk/bsd.pkg.mk"
