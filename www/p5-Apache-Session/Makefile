# $NetBSD: Makefile,v 1.7 2002/10/20 23:35:09 seb Exp $
#

DISTNAME=		Apache-Session-1.54
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ase
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module to provide persistent storage

DEPENDS+=		p5-Storable>=1.0.11:../../devel/p5-Storable/
DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5/

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
