# $NetBSD: Makefile,v 1.14 2004/11/12 17:36:40 seb Exp $
#

DISTNAME=		Apache-Session-1.6
PKGNAME=		p5-${DISTNAME}0
SVR4_PKGNAME=		p5ase
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Session/
COMMENT=		Perl5 module to provide persistent storage

DEPENDS+=		p5-Storable>=1.0.11:../../devel/p5-Storable
DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
