# $NetBSD: Makefile,v 1.9 2001/04/30 03:46:33 jlam Exp $
#

DISTNAME=	csacek-2.1.4
PKGNAME=	ap-csacek-2.1.4
CATEGORIES=	www
MASTER_SITES=	http://www.csacek.cz/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
# Note the homepage is in czech language only
HOMEPAGE=	http://www.csacek.cz/
COMMENT=	on-fly code set recoder

DEPENDS+=	apache*-1.3*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

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
