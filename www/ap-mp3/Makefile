# $NetBSD: Makefile,v 1.5 2003/02/17 17:50:12 grant Exp $
#

DISTNAME=	mod_mp3-0.35
PKGNAME=	${DISTNAME:C|mod_|ap-|}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tangent.org/pub/apache/ \
		http://software.tangent.org/download/

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://software.tangent.org/media/
COMMENT=	apache module for streaming mp3 files

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRCDIR=	${WRKSRC}/src
APACHE_MODULE_SRC=	common.c directives.c encode.c ice.c id3.c
APACHE_MODULE_SRC+=	internal_dispatch.c load.c log.c mod_mp3.c
APACHE_MODULE_SRC+=	ogg.c shout.c utility.c

DOC_DIR=	${PREFIX}/share/httpd/htdocs/manual/mod/mod_mp3

post-install:
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/faq.html ${DOC_DIR}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
