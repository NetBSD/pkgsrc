# $NetBSD: Makefile,v 1.20 2006/03/04 21:30:59 jlam Exp $
#

DISTNAME=		Apache-Session-1.80
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ase
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Session/
COMMENT=		Perl5 module to provide persistent storage

DEPENDS+=		p5-Storable>=1.0.11:../../devel/p5-Storable
DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5

PERL5_PACKLIST=		auto/Apache/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
