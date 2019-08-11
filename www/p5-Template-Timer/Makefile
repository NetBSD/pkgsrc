# $NetBSD: Makefile,v 1.16 2019/08/11 13:25:01 wiz Exp $

DISTNAME=	Template-Timer-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-Timer
COMMENT=	Rudimentary profiling for Template Toolkit
LICENSE=	gnu-gpl-v3 # OR artistic-2.0

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Template/Timer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
