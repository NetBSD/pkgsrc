# $NetBSD: Makefile,v 1.6 2000/08/01 02:12:01 wiz Exp $
#

DISTNAME=		Apache-ASP-0.05
PKGNAME=		p5-Apache-ASP-0.05
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/CHAMAS/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Apache-ASP/ASP.html

DEPENDS+=		p5-libwww>=5.48:../../www/p5-libwww
DEPENDS+=		p5-MLDBM>=2.00:../../devel/p5-MLDBM
DEPENDS+=		ap-perl>=1.19:../../www/ap-perl

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
