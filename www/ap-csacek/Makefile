# $NetBSD: Makefile,v 1.16 2003/02/17 23:18:15 grant Exp $
#

DISTNAME=	csacek-2.1.9
PKGNAME=	ap-csacek-2.1.9
CATEGORIES=	www
MASTER_SITES=	http://www.csacek.cz/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
# Note the homepage is in czech language only
HOMEPAGE=	http://www.csacek.cz/
COMMENT=	on-fly code set recoder

USE_BUILDLINK2=	YES

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+= --with-templatedir=${PREFIX}/share/csacek \
		--with-target=Apache \
		--with-apxs=${LOCALBASE}/sbin/apxs

do-install:
	@${INSTALL_DATA} ${WRKSRC}/mod_csacek.so ${PREFIX}/lib/httpd/
	@${INSTALL_DATA_DIR} ${PREFIX}/share/csacek
	@${INSTALL_DATA} ${WRKSRC}/templates/whichcode_template.html \
		${PREFIX}/share/csacek/

.include "../../devel/zlib/buildlink2.mk"
.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
