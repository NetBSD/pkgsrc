# $NetBSD: Makefile,v 1.7 2003/06/02 01:16:02 jschauma Exp $

DISTNAME=		HTML-Mason-1.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hma
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.masonhq.com/
COMMENT=		Perl-based web site development and delivery system

DEPENDS+=               p5-MLDBM>=2.0:../../databases/p5-MLDBM
DEPENDS+=		p5-gdbm-[0-9]*:../../databases/p5-gdbm
DEPENDS+=               p5-Params-Validate>=0.04:../../devel/p5-Params-Validate

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Mason/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
