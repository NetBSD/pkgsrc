# $NetBSD: Makefile,v 1.8 2001/02/17 17:22:19 wiz Exp $
#

DISTNAME=		Apache-ASP-0.05
PKGNAME=		p5-Apache-ASP-0.05
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/CHAMAS/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Apache-ASP/ASP.html
COMMENT=		perl5/Apache module of Perl-coded Active Server Pages

DEPENDS+=		ap-perl>=1.19:../../www/ap-perl
DEPENDS+=		p5-Devel-Symdump>=2.00:../../devel/p5-Devel-Symdump
DEPENDS+=		p5-MLDBM>=2.00:../../devel/p5-MLDBM
DEPENDS+=		p5-libwww>=5.48:../../www/p5-libwww

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/ASP/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
