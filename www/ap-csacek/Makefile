# $NetBSD: Makefile,v 1.2 2000/03/16 14:11:37 wiz Exp $
#

DISTNAME=	csacek-2.1.3
PKGNAME=	ap-csacek-2.1.3
CATEGORIES=	www
MASTER_SITES=	http://www.csacek.cz/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
# Note the homepage is in czech language only
HOMEPAGE=	http://www.csacek.cz/

DEPENDS+=	apache*-1.3*:../../www/apache

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+= --with-templatedir=${PREFIX}/share/csacek \
		--with-target=Apache

do-install:
	@${INSTALL_DATA} ${WRKSRC}/mod_csacek.so ${PREFIX}/lib/httpd/
	@${INSTALL_DATA_DIR} ${PREFIX}/share/csacek
	@${INSTALL_DATA} ${WRKSRC}/templates/whichcode_template.html \
		${PREFIX}/share/csacek/

.include "../../mk/bsd.pkg.mk"
