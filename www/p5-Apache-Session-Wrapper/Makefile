# $NetBSD: Makefile,v 1.5 2005/02/23 17:10:47 wiz Exp $

DISTNAME=		Apache-Session-Wrapper-0.17
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Session-Wrapper/
COMMENT=		Perl5 module doing a wrapper around Apache::Session

DEPENDS+=               p5-Class-Container-[0-9]*:../../devel/p5-Class-Container
DEPENDS+=               p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=               p5-Apache-Session>=1.6:../../www/p5-Apache-Session

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Session/Wrapper/.packlist
PERL5_USES_MODULE_BUILD=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
