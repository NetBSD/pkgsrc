# $NetBSD: Makefile,v 1.2 2004/11/07 11:20:58 kristerw Exp $

DISTNAME=		Apache-Session-Wrapper-0.17
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~drolsky/Apache-Session-Wrapper-0.17/
COMMENT=		Perl5 module doing a wrapper around Apache::Session

DEPENDS+=               p5-Apache-Session>=1.6:../../www/p5-Apache-Session
BUILD_DEPENDS+=		p5-Module-Build>=0.20:../../devel/p5-Module-Build

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Session/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
