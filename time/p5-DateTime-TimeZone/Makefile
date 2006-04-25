# $NetBSD: Makefile,v 1.7 2006/04/25 13:59:06 hiramatsu Exp $

DISTNAME=	DateTime-TimeZone-0.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-TimeZone/
COMMENT=	Perl module to handle time zone manipulation

DEPENDS+=	p5-Class-Singleton>=1.03:../../devel/p5-Class-Singleton
DEPENDS+=	p5-Params-Validate>=0.72:../../devel/p5-Params-Validate

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/TimeZone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
