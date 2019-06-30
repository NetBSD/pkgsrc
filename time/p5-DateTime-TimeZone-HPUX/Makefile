# $NetBSD: Makefile,v 1.13 2019/06/30 20:17:16 nia Exp $

DISTNAME=	DateTime-TimeZone-HPUX-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-TimeZone-HPUX
COMMENT=	Handles timezones defined at the operating system level on HP-UX
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-TimeZone>=1.05:../../time/p5-DateTime-TimeZone

ONLY_FOR_PLATFORM=	HPUX-*-*

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/TimeZone/HPUX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
