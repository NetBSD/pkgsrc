# $NetBSD: Makefile,v 1.5 1999/11/21 22:12:59 tron Exp $
#

PKGNAME=	ap-${DISTNAME}

DEPENDS+=	apache-1.3.*:../../www/apache

USE_PERL5=	yes

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs
CONFIGURE_ENV+=		PERL_PATH=${LOCALBASE}/bin/perl

BUILDING_SERVER_MODULE=yes

do-install:
	@cd ${WRKSRC} && ${CP} libphp3.so mod_php3.so
	@${PREFIX}/sbin/apxs -i ${WRKSRC}/mod_php3.so

.include "../php3/Makefile"
