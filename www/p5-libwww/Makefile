# $NetBSD: Makefile,v 1.8 1999/01/11 22:35:14 kim Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/14 04:00:11 jfitz Exp
#

PKGNAME=        	p5-libwww-5.36
DISTNAME!=       	echo ${PKGNAME} | sed -e 's/^p5-//' -e 's/-/-perl-/'
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	URI

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/MD5.pm:../../security/p5-MD5 \
		${PREFIX}/lib/perl5/site_perl/Net/FTP.pm:../../net/p5-Net \
		${PREFIX}/lib/perl5/site_perl/MIME/Base64.pm:../../converters/p5-MIME-Base64 \
		${PREFIX}/lib/perl5/site_perl/HTML/Parser.pm:../../libwww/p5-HTML-Parser

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
