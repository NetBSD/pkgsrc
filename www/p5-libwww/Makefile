# $NetBSD: Makefile,v 1.7 1998/06/22 13:14:31 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/14 04:00:11 jfitz Exp
#

DISTNAME=       	libwww-perl-5.12
PKGNAME=        	p5-libwww-5.12
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	URI

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/MD5.pm:../../security/p5-MD5 \
		${PREFIX}/lib/perl5/site_perl/Net/FTP.pm:../../net/p5-Net \
		${PREFIX}/lib/perl5/site_perl/MIME/Base64.pm:../../converters/p5-MIME-Base64

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
