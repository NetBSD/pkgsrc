# $NetBSD: Makefile,v 1.9 2005/04/11 21:47:55 tv Exp $

DISTNAME=		Apache-Session-Wrapper-0.19
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Session-Wrapper/
COMMENT=		Perl5 module doing a wrapper around Apache::Session

DEPENDS+=               p5-Class-Container-[0-9]*:../../devel/p5-Class-Container
DEPENDS+=               p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=               p5-Apache-Session>=1.6:../../www/p5-Apache-Session

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Session/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
