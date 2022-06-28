# $NetBSD: Makefile,v 1.25 2022/06/28 11:36:51 wiz Exp $

DISTNAME=	Calendar-Simple-v2.0.1
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Calendar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Calendar-Simple
COMMENT=	Perl extension to create simple calendars
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Calendar/Simple/.packlist

PERL5_MODULE_TYPE=	Module::Build

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
