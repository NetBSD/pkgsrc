# $NetBSD: Makefile,v 1.19 2005/11/23 22:20:24 wiz Exp $
#

DISTNAME=		Apache-Session-1.80
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ase
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Session/
COMMENT=		Perl5 module to provide persistent storage

DEPENDS+=		p5-Storable>=1.0.11:../../devel/p5-Storable
DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5

PERL5_PACKLIST=		auto/Apache/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
