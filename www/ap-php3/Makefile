# $NetBSD: Makefile,v 1.4 1999/06/15 22:24:12 tron Exp $
#

PKGNAME=	ap-${DISTNAME}

DEPENDS+=	apache-1.3.6p0:../../www/apache

USE_PERL5=	yes

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs
CONFIGURE_ENV+=		PERL_PATH=${LOCALBASE}/bin/perl

BUILDING_SERVER_MODULE=yes

do-install:
	@cd ${WRKSRC} && ${CP} libphp3.so mod_php3.so
	@${PREFIX}/sbin/apxs -i ${WRKSRC}/mod_php3.so

.include "../php3/Makefile"
