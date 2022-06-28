# $NetBSD: Makefile,v 1.24 2022/06/28 11:36:58 wiz Exp $

DISTNAME=	Time-Format-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
