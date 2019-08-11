# $NetBSD: Makefile,v 1.19 2019/08/11 13:24:53 wiz Exp $
#

DISTNAME=	LWP-UserAgent-Determined-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LWP-UserAgent-Determined
COMMENT=	Perl5 virtual browser that retries errors
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/UserAgent/Determined/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
