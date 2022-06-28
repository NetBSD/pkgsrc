# $NetBSD: Makefile,v 1.14 2022/06/28 11:37:36 wiz Exp $

DISTNAME=	LWP-Protocol-PSGI-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LWP-Protocol-PSGI
COMMENT=	Perl extension to override LWP HTTP/HTTPS backend with your PSGI app
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Plack>=0:../../www/p5-Plack
DEPENDS+=	p5-libwww>=6.06:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Protocol/PSGI/.packlist

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
