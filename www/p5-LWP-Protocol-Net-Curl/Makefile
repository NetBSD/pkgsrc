# $NetBSD: Makefile,v 1.7 2022/06/28 11:37:36 wiz Exp $

DISTNAME=	LWP-Protocol-Net-Curl-0.026
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SY/SYP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/LWP::Protocol::Net::Curl
COMMENT=	Provide Curl support for LWP::UserAgent
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTTP-Date>=6.02:../../www/p5-HTTP-Date
DEPENDS+=	p5-ParallelUserAgent>=2.62:../../www/p5-ParallelUserAgent
DEPENDS+=	p5-Net-Curl>=0.39:../../www/p5-Net-Curl
DEPENDS+=	p5-URI>=1.74:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Protocol/Net/Curl/.packlist

TEST_TARGET?=	# to skip make test (but can be enabled by 'env TEST_TARGET=test make test')

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
