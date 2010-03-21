# $NetBSD: Makefile,v 1.17 2010/03/21 16:29:44 wiz Exp $
#

DISTNAME=	mod_mp3-0.35
PKGNAME=	${DISTNAME:C|mod_|ap13-|}
CATEGORIES=	www
MASTER_SITES=	http://www.tangent.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tangent.org/index.pl?lastnode_id=478&node_id=380
COMMENT=	Apache module for streaming mp3 files

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-mp3-[0-9]*

APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRCDIR=	${WRKSRC}/src
APACHE_MODULE_SRC=	common.c directives.c encode.c ice.c id3.c
APACHE_MODULE_SRC+=	internal_dispatch.c load.c log.c mod_mp3.c
APACHE_MODULE_SRC+=	ogg.c shout.c utility.c

DOC_DIR=	${PREFIX}/share/httpd/htdocs/manual/mod/mod_mp3

INSTALLATION_DIRS+=	${DOC_DIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/faq.html ${DESTDIR}${DOC_DIR}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
