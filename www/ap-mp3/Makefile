# $NetBSD: Makefile,v 1.1.1.1 2002/02/25 03:00:49 grant Exp $
#

DISTNAME=	mod_mp3-0.35
PKGNAME=	ap-mp3-0.35
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tangent.org/pub/apache/ \
		http://software.tangent.org/download/

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://software.tangent.org/media/
COMMENT=	apache module for streaming mp3 files

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

DOC_DIR=	${PREFIX}/share/httpd/htdocs/manual/mod/mod_mp3

do-build:
	@cd ${WRKSRC}/src && ${PREFIX}/sbin/apxs -c -o mod_mp3.so \
		directives.c \
		encode.c \
		ice.c \
		load.c \
		mod_mp3.c \
		shout.c \
		utility.c \
		ogg.c \
		common.c \
		id3.c \
		log.c \
		internal_dispatch.c

do-install:
	@cd ${WRKSRC}/src && ${PREFIX}/sbin/apxs -i mod_mp3.so
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/faq.html ${DOC_DIR}

.include "../../mk/bsd.pkg.mk"
