# $NetBSD: Makefile,v 1.5 2000/07/27 16:32:01 hubertf Exp $
#

DISTNAME=		Apache-ASP-0.05
PKGNAME=		p5-Apache-ASP-0.05
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/CHAMAS/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Apache-ASP/ASP.html

DEPENDS+=		libwww-perl-5.*:../../www/p5-libwww
DEPENDS+=		MLDBM-2.*:devel/p5-MLDBM
DEPENDS+=		mod_perl-1.*:../../www/ap-perl

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
