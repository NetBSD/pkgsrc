# $NetBSD: Makefile,v 1.15 2008/08/23 07:47:00 obache Exp $
#

DISTNAME=	mod_mp3-0.35
PKGNAME=	${DISTNAME:C|mod_|ap13-|}
CATEGORIES=	www
MASTER_SITES=	http://www.tangent.org/download/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://tangent.org/index.pl?lastnode_id=478&node_id=380
COMMENT=	Apache module for streaming mp3 files

CONFLICTS=	ap-mp3-[0-9]*

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
