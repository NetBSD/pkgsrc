# $NetBSD: Makefile,v 1.16 2019/08/11 13:24:55 wiz Exp $

DISTNAME=	PSGI-1.102
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PSGI
COMMENT=	Perl Web Server Gateway Interface Specification
LICENSE=	${PERL5_LICENSE}

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/PSGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
