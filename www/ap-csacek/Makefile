# $NetBSD: Makefile,v 1.5 2000/08/29 19:03:51 jlam Exp $
#

DISTNAME=	csacek-2.1.4
PKGNAME=	ap-csacek-2.1.4
CATEGORIES=	www
MASTER_SITES=	http://www.csacek.cz/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
# Note the homepage is in czech language only
HOMEPAGE=	http://www.csacek.cz/

DEPENDS+=	apache*-1.3*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	${PERL5}:../../lang/perl5

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+= --with-templatedir=${PREFIX}/share/csacek \
		--with-target=Apache
MAKE_ENV+=	LOCALBASE=${LOCALBASE}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/mod_csacek.so ${PREFIX}/lib/httpd/
	@${INSTALL_DATA_DIR} ${PREFIX}/share/csacek
	@${INSTALL_DATA} ${WRKSRC}/templates/whichcode_template.html \
		${PREFIX}/share/csacek/

.include "../../mk/bsd.pkg.mk"
