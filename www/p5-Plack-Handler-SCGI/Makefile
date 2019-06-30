# $NetBSD: Makefile,v 1.13 2019/06/30 20:17:40 nia Exp $

DISTNAME=	Plack-Handler-SCGI-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Handler-SCGI
COMMENT=	PSGI handler on SCGI daemon
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Plack/Handler/SCGI/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Plack>=0.9901:../../www/p5-Plack
DEPENDS+=	p5-SCGI-[0-9]*:../../www/p5-SCGI
DEPENDS+=	p5-Try-Tiny>=0.04:../../devel/p5-Try-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
