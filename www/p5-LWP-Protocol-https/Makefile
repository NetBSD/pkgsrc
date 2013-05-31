# $NetBSD: Makefile,v 1.10 2013/05/31 12:42:48 wiz Exp $

DISTNAME=	LWP-Protocol-https-6.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LWP-Protocol-https/
COMMENT=	Provide https support for LWP::UserAgent
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.02

DEPENDS+=	p5-IO-Socket-SSL>=1.38:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Mozilla-CA>=20110101:../../security/p5-Mozilla-CA

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Protocol/https/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
