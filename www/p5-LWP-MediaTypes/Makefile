# $NetBSD: Makefile,v 1.15 2019/08/11 13:24:52 wiz Exp $

DISTNAME=	LWP-MediaTypes-6.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LWP-MediaTypes
COMMENT=	Guess media type for a file or a URL
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/MediaTypes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
