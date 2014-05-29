# $NetBSD: Makefile,v 1.12 2014/05/29 23:37:53 wiz Exp $
#

DISTNAME=	Time-Format-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Format/
COMMENT=	Easy-to-use date/time formatting

DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip

PERL5_PACKLIST=	auto/Time/Format/.packlist
USE_LANGUAGES=	# none

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
