# $NetBSD: Makefile,v 1.18 2022/06/28 11:36:54 wiz Exp $

DISTNAME=	DateTime-Format-DateParse-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DateTime::Format::DateParse
COMMENT=	Parses Date::Parse compatible formats
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.2900:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-TimeZone>=0.27:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=		#

PERL5_PACKLIST=	auto/DateTime/Format/DateParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
