# $NetBSD: Makefile,v 1.11 2001/05/20 05:23:27 jonb Exp $
#

DISTNAME=	csacek-2.1.6
PKGNAME=	ap-csacek-2.1.6
CATEGORIES=	www
MASTER_SITES=	http://www.csacek.cz/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
# Note the homepage is in czech language only
HOMEPAGE=	http://www.csacek.cz/
COMMENT=	on-fly code set recoder

DEPENDS+=	apache{,6}-1.3*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+= --with-templatedir=${PREFIX}/share/csacek \
		--with-target=Apache \
		--with-apxs=${LOCALBASE}/sbin/apxs

do-install:
	@${INSTALL_DATA} ${WRKSRC}/mod_csacek.so ${PREFIX}/lib/httpd/
	@${INSTALL_DATA_DIR} ${PREFIX}/share/csacek
	@${INSTALL_DATA} ${WRKSRC}/templates/whichcode_template.html \
		${PREFIX}/share/csacek/

.include "../../mk/bsd.pkg.mk"
