# $NetBSD: Makefile,v 1.1.1.1 1998/12/05 03:48:46 tv Exp $
#

DISTNAME=		Apache-ASP-0.05
PKGNAME=		p5-Apache-ASP-0.05
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache/CHAMAS

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Apache-ASP/

# all other needs are already pulled in by p5-libwww
BUILD_DEPENDS=		${PREFIX}/lib/perl5/site_perl/URI/URL.pm:../../www/p5-libwww \
			${PREFIX}/lib/perl5/site_perl/MLDBM.pm:../../devel/p5-MLDBM \
			${PREFIX}/lib/httpd/mod_perl.so:../../www/ap-perl
RUN_DEPENDS=		${BUILD_DEPENDS}

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
