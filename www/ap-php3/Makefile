# $NetBSD: Makefile,v 1.7 2001/02/17 17:21:51 wiz Exp $
#

PKGNAME=	ap-${DISTNAME}

COMMENT=	PHP3 server module for Apache

DEPENDS+=	apache-1.3.*:../../www/apache

USE_PERL5=	# defined

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs
CONFIGURE_ENV+=		PERL_PATH=${PERL5}

BUILDING_SERVER_MODULE=	yes

do-install:
	@cd ${WRKSRC} && ${CP} libphp3.so mod_php3.so
	@${PREFIX}/sbin/apxs -i ${WRKSRC}/mod_php3.so

.include "../php3/Makefile"
