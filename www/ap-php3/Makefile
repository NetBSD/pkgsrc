# $NetBSD: Makefile,v 1.6 2000/08/27 02:46:07 jlam Exp $
#

PKGNAME=	ap-${DISTNAME}

DEPENDS+=	apache-1.3.*:../../www/apache

USE_PERL5=	# defined

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs
CONFIGURE_ENV+=		PERL_PATH=${PERL5}

BUILDING_SERVER_MODULE=	yes

do-install:
	@cd ${WRKSRC} && ${CP} libphp3.so mod_php3.so
	@${PREFIX}/sbin/apxs -i ${WRKSRC}/mod_php3.so

.include "../php3/Makefile"
