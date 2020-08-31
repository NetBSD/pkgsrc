# $NetBSD: Makefile,v 1.21 2020/08/31 18:12:26 wiz Exp $
#

DISTNAME=	Time-Format-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Time-Format
COMMENT=	Easy-to-use date/time formatting

DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip

PERL5_PACKLIST=	auto/Time/Format/.packlist
USE_LANGUAGES=	# none

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
